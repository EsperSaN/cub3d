/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:17:59 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:47 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

void	puterror(char *msg)
{
	write(STDERR_FILENO, "Error : ", 8);
	while (*msg)
	{
		write(STDERR_FILENO, msg, 1);
		msg++;
	}
	write(STDERR_FILENO, "\n", 1);
}
