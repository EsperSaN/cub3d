/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_readable_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:28:03 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:36 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

// just to check if the file canbe open and read

bool	is_file_readable(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	ft_putstr_fd("open ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(" : ", 1);
	if (fd == -1)
	{
		perror("");
		return (false);
	}
	if (fd > 0)
		close(fd);
	ft_putstr_fd("OK!!\n", 1);
	return (true);
}
