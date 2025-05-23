/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:18:34 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:42:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	main_render(void *d)
{
	t_data		*data;

	data = (t_data *)d;
	clear_image(data->img_game, get_rgba(0, 0, 0, 255));
	floor_cast(data->img_game, data->texture->floor_color);
	ceil_cast(data->img_game, data->texture->ceil_color);
	ray_casting(data->img_game, data);
}
