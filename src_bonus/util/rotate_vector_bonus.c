/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:27:11 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 13:18:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

t_float_point	rotate_vector(t_float_point vec, float angle)
{
	t_float_point	tmp;

	tmp.x = vec.x;
	tmp.y = vec.y;
	vec.x = tmp.x * ft_cos(angle) - tmp.y * ft_sin(angle);
	vec.y = tmp.x * ft_sin(angle) + tmp.y * ft_cos(angle);
	return (vec);
}
