/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:50:23 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:43:58 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	floor_cast(mlx_image_t *img, int color)
{
	int			cur_x;
	t_int_point	start;
	t_int_point	end;

	cur_x = 0;
	start.y = (int)img->height / 2;
	end.y = (int)img->height - 1;
	while (cur_x < (int)img->width)
	{
		start.x = cur_x;
		end.x = cur_x;
		draw_line(img, start, end, color);
		cur_x++;
	}
}
