/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:55:02 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:33:29 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	init_window(t_data *data)
{
	data->mlx = mlx_init(1024, 768, "cub3d", false);
	if (data->mlx == NULL)
		return (puterror(MLX_INIT_FAIL), false);
	data->img_game = mlx_new_image(data->mlx, 1024, 768);
	if (data->img_game == NULL || \
		mlx_image_to_window(data->mlx, data->img_game, 0, 0) == -1)
		return (puterror(MLX_IMG_FAIL), false);
	data->img_maps = NULL;
	return (true);
}

bool	prepare_render(t_data *data)
{
	if (init_window(data) == false)
		return (false);
	putreport("init window done");
	return (true);
}
