/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_file_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:40:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:26 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

char	*get_texture_file(char **map, char *indicater)
{
	int		i;
	char	**tmp;
	char	*ret;

	i = 0;
	while (map[i])
	{
		tmp = ft_split(map[i], ' ');
		if (tmp != NULL && is_same_str(tmp[0], indicater) && tmp[1] != NULL)
		{
			ret = ft_strdup(tmp[1]);
			free2d(tmp);
			return (ret);
		}
		free2d(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}
