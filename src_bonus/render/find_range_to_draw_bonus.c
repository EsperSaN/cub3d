/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_range_to_draw_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:00 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:17:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	find_range_to_draw(t_raydata *ray, int img_height)
{
	ray->line_hight = (int)(img_height / ray->perp_wall_distant);
	ray->line_s = (-ray->line_hight / 2) + (img_height / 2);
	if (ray->line_s < 0)
		ray->line_s = 0;
	ray->line_e = (ray->line_hight / 2) + (img_height / 2);
	if (ray->line_e >= img_height)
		ray->line_e = img_height - 1;
}
