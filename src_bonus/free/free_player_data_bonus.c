/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:32:53 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:14:53 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_bonus.h"

t_player_data	*free_player(t_player_data *data)
{
	if (data != NULL)
		free(data);
	return (NULL);
}
