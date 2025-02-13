/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:13:36 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:44 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

bool	is_same_str(char *s1, char *s2)
{
	bool	ret;

	ret = true;
	if (!s1 || !s2)
		return (false);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			ret = false;
		s2++;
		s1++;
	}
	if (*s1 != '\0' || *s2 != '\0')
		ret = false;
	return (ret);
}
