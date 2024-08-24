/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putreport_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:22:18 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:50 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

void	putreport(char *msg)
{
	write(STDOUT_FILENO, "REPORT: ", 8);
	while (*msg)
	{
		write(STDOUT_FILENO, msg, 1);
		msg++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return ;
}
