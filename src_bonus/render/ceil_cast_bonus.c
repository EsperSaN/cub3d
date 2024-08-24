/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_cast_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:44:37 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:44:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ceil_cast(mlx_image_t *img, int color)
{
	int			cur_x;
	t_int_point	start;
	t_int_point	end;

	cur_x = 0;
	end.y = (int)img->height / 2;
	start.y = 0;
	while (cur_x < (int)img->width)
	{
		start.x = cur_x;
		end.x = cur_x;
		draw_line(img, start, end, color);
		cur_x++;
	}
}
