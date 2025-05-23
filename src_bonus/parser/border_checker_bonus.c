/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:12 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 16:51:45 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

#define LEAK_MAP "player map are leaks or not surrounding with wall!!!\n"

int	is_map_not_sp(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' \
		|| c == 'N' || c == '0' || c == '1')
		return (1);
	return (0);
}

int	border_checker(t_parser_data *data, char **map)
{
	int		i;
	int		h;
	int		j;
	char	**visited;

	visited = ft_floodfill(data);
	i = 0;
	h = data->height;
	while (i < h)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && is_map_not_sp(map[i][j]) \
				&& visited[i][j] == '3')
				if (i == 0 || i == h - 1 || !is_map_not_sp(map[i][j - 1]) \
						|| !is_map_not_sp(map[i + 1][j]) \
							|| !is_map_not_sp(map[i - 1][j]) \
								|| !is_map_not_sp(map[i][j + 1]))
					return (ft_putstr_fd(LEAK_MAP, 1), free2d(visited), 0);
			j++;
		}
		i++;
	}
	return (free2d(visited), 1);
}
