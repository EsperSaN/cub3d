/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:34:06 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:14:57 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_bonus.h"

t_texture	*free_texture(t_texture *data)
{
	int		height;

	height = 0;
	if (data != NULL)
	{
		while (height < data->height)
		{
			free(data->pixel_array[height]);
			data->pixel_array[height] = NULL;
			height++;
		}
		free(data->pixel_array);
		free(data);
	}
	return (NULL);
}

t_texture	*free_texture2(t_texture *data, int i)
{
	int		height;

	height = 0;
	if (data != NULL)
	{
		while (height < i && height < data->height)
		{
			free(data->pixel_array[height]);
			data->pixel_array[height] = NULL;
			height++;
		}
		free(data->pixel_array);
		free(data);
	}
	return (NULL);
}
