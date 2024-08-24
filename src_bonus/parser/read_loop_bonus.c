/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:57 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

char	*read_loop(int read_co, char *chdata, int fd, char *buffer)
{
	char	*tmp;

	while (read_co > 0)
	{
		tmp = chdata;
		read_co = read(fd, buffer, READ_SIZE);
		buffer[read_co] = '\0';
		chdata = ft_strjoin(tmp, buffer);
		if (!chdata)
			return (puterror(": Fatal"), free(buffer), free(tmp), NULL);
		if (false == ft_isprint_mk2(buffer[0]))
			read_co = 0;
		free(tmp);
	}
	free(buffer);
	if (read_co < -1)
		perror("FILE READER : ");
	return (chdata);
}
