/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_extension_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:26:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:41 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

// to check for the last file extention consider the filename.txt.cub

bool	is_right_extension(char *file_name, char *extension)
{
	if (!is_same_str(extension, ft_strrchr(file_name, '.')))
	{
		ft_putstr_fd(file_name, 1);
		ft_putstr_fd(" : not right extention!!!\n", 1);
		return (false);
	}
	return (true);
}
