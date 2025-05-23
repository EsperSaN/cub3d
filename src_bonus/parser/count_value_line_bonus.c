/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_value_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:28 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:15:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	count_value_line(char **data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data[i])
	{
		if (is_map_line(data[i]) == -1)
			break ;
		k += is_map_line(data[i]);
		i++;
	}
	if (k != 6)
		return (-1);
	return (1);
}
