/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:03:12 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:15:16 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free2d(char **ptr)
{
	char	**tmp;

	tmp = ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}
