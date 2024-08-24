/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:45:56 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

float	ft_cos(float degree)
{
	float	radian;

	radian = get_rad(degree);
	return (cosf(radian));
}
