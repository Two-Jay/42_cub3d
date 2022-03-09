/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic_opreator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:13:27 by gilee             #+#    #+#             */
/*   Updated: 2022/03/09 17:14:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vec	vec_add(t_vec vec1, t_vec vec2)
{
	vec1.x = vec1.x + vec2.x;
	vec1.y = vec1.y + vec2.y;
	return (vec1);
}

t_vec	vec_minus(t_vec vec1, t_vec vec2)
{
	vec1.x = vec1.x - vec2.x;
	vec1.y = vec1.y - vec2.y;
	return (vec1);
}

t_vec	vec_scala_mul(t_vec vec, double n)
{
	vec.x = vec.x * n;
	vec.y = vec.y * n;
	return (vec);
}
