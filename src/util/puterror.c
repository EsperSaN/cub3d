/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:17:59 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 14:02:29 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	puterror(char *msg)
{
	write(STDERR_FILENO, "Error\n: ", 8);
	while (*msg)
	{
		write(STDERR_FILENO, msg, 1);
		msg++;
	}
	write(STDERR_FILENO, "\n", 1);
}
