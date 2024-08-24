/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_element_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:31 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	is_map_element(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' \
		|| c == 'N' || c == '0' || c == '1' || ft_isspace(c))
		return (1);
	return (0);
}
