# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 22:39:14 by pruenrua          #+#    #+#              #
#    Updated: 2024/06/13 17:07:41 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes -s ./$(NAME) maps/valid/subject.cub
# lib source

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
MLXLINK_FLAG = -ldl -lglfw -pthread -lm
else ifeq ($(UNAME), Darwin)
MLXLINK_FLAG = -framework Cocoa -framework OpenGL -framework IOKit -L/opt/homebrew/opt/glfw/lib -lglfw
else
MLXLINK_FLAG = -lglfw3 -lopengl32 -lgdi32
endif

LIB_DIR = ./lib
LIB_MLX_DIR = $(LIB_DIR)/MLX42
LIB_FT_DIR = $(LIB_DIR)/libft
LIB_FILE = $(LIB_FT_DIR)/libft.a \
		   $(LIB_MLX_DIR)/build/libmlx42.a
# MLXLINK_FLAG = -ldl -lglfw -pthread -lm
LIB_LINK = -L$(LIB_FT_DIR) -L$(LIB_MLX_DIR)/build

# manda###################################################################33333
SRC_DIR = ./src
INC_DIR = $(SRC_DIR)/include/
BUILD_DIR = $(SRC_DIR)/build

#--library-directory
INCLUDE_FLAG = -I$(LIB_FT_DIR)/ \
			   -I$(LIB_FT_DIR)/get_next_line/\
			   -I$(LIB_MLX_DIR)/build/ \
			   -I$(LIB_MLX_DIR)/include/MLX42/ \
			   -I$(INC_DIR)

#header source
HEADER_FILE = cube.h\
		 	define.h\
		 	free.h\
		 	parser.h\
		 	render.h\
		 	util.h
HEADER_SRC = $(addprefix $(INC_DIR), $(HEADER_FILE))

#render source
RENDER_FILE = clear_image.c\
			  do_dda.c\
			  draw_line_with_texture.c\
			  find_range_to_draw.c\
			  init_ray.c\
			  draw_line.c\
			  prepare_render.c\
			  key_hook.c\
			  floor_cast.c\
			  ceil_cast.c\
			  ray_casting.c\
			  main_render.c
RENDER_DIR = $(SRC_DIR)/render/
RENDER_SRCS = $(addprefix $(RENDER_DIR), $(RENDER_FILE))

#util source
UTIL_FILE = puterror.c \
		    putreport.c \
			is_same_str.c \
			is_right_extension.c \
			is_file_valid.c \
			is_file_readable.c \
			get_rgba.c \
			get_rad.c \
			get_png_texture.c \
			ft_cos.c \
			ft_sin.c \
			rotate_vector.c
UTIL_DIR = $(SRC_DIR)/util/
UTIL_SRCS = $(addprefix $(UTIL_DIR), $(UTIL_FILE))

#parser source
PARSER_FILE = \
		get_element_check.c\
		ft_split_no_cut.c\
		border_checker.c \
		check_resource.c \
		count_value_line.c \
		file_reader.c \
		find_first_of.c \
		find_height_width.c \
		find_last_of.c \
		free_2dwithres.c \
		ft_floodfill.c \
		ft_isprint_mk2.c \
		ft_isspace.c \
		get_ceil_floor.c \
		get_texture_file.c \
		init_map.c \
		is_map_element.c \
		is_map_line.c \
		is_numline.c \
		main_parser.c \
		read_loop.c \
		scan4player.c \
		set_from_parser_data.c \
		set_maps_data.c \
		set_texture_assets.c \
		src_checker.c 
PARSER_DIR = $(SRC_DIR)/parser/
PARSER_SRCS = $(addprefix $(PARSER_DIR), $(PARSER_FILE))

# free source
FREE_FILE = free_maps_data.c\
			free_parser_data.c\
			free_player_data.c\
			free_texture_assets.c\
			free_texture.c\
			term_and_cleanup.c\
			free_two_d.c

FREE_DIR = $(SRC_DIR)/free/
FREE_SRCS = $(addprefix $(FREE_DIR), $(FREE_FILE))

# all source before compile
SRCS = $(UTIL_SRCS) \
	   $(FREE_SRCS) \
	   $(PARSER_SRCS) \
	   $(RENDER_SRCS) \
	   ./src/main.c

# rule
all : libmlx libft $(NAME)

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

$(OBJS): $(BUILD_DIR)/%.o: %.c $(HEADER_SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FILE) $(LIB_LINK) $(MLXLINK_FLAG)

clean :
	make -C $(LIB_FT_DIR) clean
	$(RM) -r $(BUILD_DIR_BONUS)
	$(RM) -r $(BUILD_DIR)

fclean : clean
	make -C $(LIB_FT_DIR) fclean
	make -C $(LIB_MLX_DIR)/build/ clean
	rm -f $(BONUS_NAME)
	rm -f $(NAME)

libmlx :
	cmake $(LIB_MLX_DIR) -B $(LIB_MLX_DIR)/build && make -C $(LIB_MLX_DIR)/build -j4

libft :
	make -C $(LIB_FT_DIR)

norm : 
	norminette $(LIB_FT_DIR) $(HEADER_SRC) $(SRCS) $(HEADER_SRC_BONUS) $(SRCS_BONUS)

re : fclean all

#bonus
SRC_DIR_BONUS = ./src_bonus
INC_DIR_BONUS = $(SRC_DIR_BONUS)/include/
BUILD_DIR_BONUS = $(SRC_DIR_BONUS)/build

OBJS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.o)

SRCS_BONUS = $(UTIL_SRCS_BONUS) \
	   $(FREE_SRCS_BONUS) \
	   $(PARSER_SRCS_BONUS) \
	   $(RENDER_SRCS_BONUS) \
	   $(SRC_DIR_BONUS)/main_bonus.c

HEADER_FILE_BONUS = cube_bonus.h\
		 	define_bonus.h\
		 	free_bonus.h\
		 	parser_bonus.h\
		 	render_bonus.h\
		 	util_bonus.h
HEADER_SRC_BONUS = $(addprefix $(INC_DIR_BONUS), $(HEADER_FILE_BONUS))
INCLUDE_FLAG_BONUS = -I$(LIB_FT_DIR)/ \
			   -I$(LIB_FT_DIR)/get_next_line/\
			   -I$(LIB_MLX_DIR)/build/ \
			   -I$(LIB_MLX_DIR)/include/MLX42/ \
			   -I$(INC_DIR_BONUS)

RENDER_FILE_BONUS = clear_image_bonus.c\
			  do_dda_bonus.c\
			  draw_line_with_texture_bonus.c\
			  find_range_to_draw_bonus.c\
			  init_ray_bonus.c\
			  draw_map_bonus.c\
			  draw_squre_bonus.c\
			  draw_line_bonus.c\
			  prepare_render_bonus.c\
			  key_hook_bonus.c\
			  floor_cast_bonus.c\
			  ceil_cast_bonus.c\
			  ray_casting_bonus.c\
			  main_render_bonus.c
RENDER_DIR_BONUS = $(SRC_DIR_BONUS)/render/
RENDER_SRCS_BONUS = $(addprefix $(RENDER_DIR_BONUS), $(RENDER_FILE_BONUS))

#util source
UTIL_FILE_BONUS = puterror_bonus.c \
		    putreport_bonus.c \
			is_same_str_bonus.c \
			is_right_extension_bonus.c \
			is_file_valid_bonus.c \
			is_file_readable_bonus.c \
			get_rgba_bonus.c \
			get_rad_bonus.c \
			get_png_texture_bonus.c \
			ft_cos_bonus.c \
			ft_sin_bonus.c \
			rotate_vector_bonus.c
UTIL_DIR_BONUS = $(SRC_DIR_BONUS)/util/
UTIL_SRCS_BONUS = $(addprefix $(UTIL_DIR_BONUS), $(UTIL_FILE_BONUS))

#parser source
PARSER_FILE_BONUS = \
		get_element_check_bonus.c\
		ft_split_no_cut_bonus.c\
		border_checker_bonus.c \
		check_resource_bonus.c \
		count_value_line_bonus.c \
		file_reader_bonus.c \
		find_first_of_bonus.c \
		find_height_width_bonus.c \
		find_last_of_bonus.c \
		free_2dwithres_bonus.c \
		ft_floodfill_bonus.c \
		ft_isprint_mk2_bonus.c \
		ft_isspace_bonus.c \
		get_ceil_floor_bonus.c \
		get_texture_file_bonus.c \
		init_map_bonus.c \
		is_map_element_bonus.c \
		is_map_line_bonus.c \
		is_numline_bonus.c \
		main_parser_bonus.c \
		read_loop_bonus.c \
		scan4player_bonus.c \
		set_from_parser_data_bonus.c \
		set_maps_data_bonus.c \
		set_texture_assets_bonus.c \
		src_checker_bonus.c 
PARSER_DIR_BONUS = $(SRC_DIR_BONUS)/parser/
PARSER_SRCS_BONUS = $(addprefix $(PARSER_DIR_BONUS), $(PARSER_FILE_BONUS))

# free source
FREE_FILE_BONUS = free_maps_data_bonus.c\
			free_parser_data_bonus.c\
			free_player_data_bonus.c\
			free_texture_assets_bonus.c\
			free_texture_bonus.c\
			term_and_cleanup_bonus.c\
			free_two_d_bonus.c

FREE_DIR_BONUS = $(SRC_DIR_BONUS)/free/
FREE_SRCS_BONUS = $(addprefix $(FREE_DIR_BONUS), $(FREE_FILE_BONUS))

BONUS_NAME = cub3D_bonus

bonus: libmlx libft $(BONUS_NAME)

$(OBJS_BONUS): $(BUILD_DIR_BONUS)/%.o: %.c $(HEADER_SRC_BONUS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE_FLAG_BONUS) -c $< -o $@
	
$(BONUS_NAME) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(LIB_FILE) $(LIB_LINK) $(MLXLINK_FLAG)

##########

.PHONY: all clean fclean norm re libmlx libft bonus
