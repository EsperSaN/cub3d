/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:17:16 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	src_checker(t_parser_data *res)
{
	if (!res->north_texture || !res->south_texture \
	|| !res->west_texture || !res->east_texture \
	|| !res->ceil_color || !res->floor_color)
		return (0);
	if (!is_file_valid(res->north_texture, ".png"))
		return (0);
	if (!is_file_valid(res->south_texture, ".png"))
		return (0);
	if (!is_file_valid(res->west_texture, ".png"))
		return (0);
	if (!is_file_valid(res->east_texture, ".png"))
		return (0);
	return (1);
}
