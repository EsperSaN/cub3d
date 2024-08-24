/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_deg_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:17:46 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:16 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

// control the deg value to not over the 0 and 360

float	abs_deg(float dregree)
{
	if (dregree > 359.9)
		return (0);
	if (dregree < 0)
		return (360);
	return (dregree);
}
