/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:32:35 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:14:49 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_bonus.h"

t_parser_data	*free_parser(t_parser_data *data)
{
	if (data != NULL)
	{
		if (data->maps_data)
			free2d(data->maps_data);
		if (data->east_texture)
			free(data->east_texture);
		if (data->north_texture)
			free(data->north_texture);
		if (data->south_texture)
			free(data->south_texture);
		if (data->west_texture)
			free(data->west_texture);
		free(data);
	}
	return (NULL);
}
