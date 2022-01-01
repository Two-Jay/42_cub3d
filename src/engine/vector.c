/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:16:18 by jekim             #+#    #+#             */
/*   Updated: 2021/12/28 23:15:01 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vec	vec_create(double x, double y)
{
	t_vec ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

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

t_vec	vec_equation(t_vec *coeff0, t_vec *coeff1, t_vec *constant)
{
	t_vec ret;
	double det;

	det = coeff0->x * coeff1->y - coeff1->x * coeff0->y;
	ret.x = (coeff1->y * constant->x - coeff1->x * constant->y) / det;
	ret.x = (coeff0->x * constant->y - coeff0->y * constant->x) / det;
	return (ret);
}

t_vec	vec_rot_ccw(t_vec a, double angle)
{
	double	sin_angle;
	double	cos_angle;
	t_vec	ret;
	
	sin_angle = sin(angle);
	cos_angle = cos(angle);
	ret.x = cos_angle * a.x - sin_angle * a.y;
	ret.y = sin_angle * a.x + cos_angle * a.y;
	return (ret);
}

t_vec	vec_rot_min_ccw(t_vec a)
{
	static double	sin_unit;
	static double	cos_unit;
	t_vec			ret;

	if (sin_unit == 0)
		sin_unit = sin(M_PI * ANGLE_MIN / 180);
	if (cos_unit == 0)
		cos_unit = cos(M_PI * ANGLE_MIN / 180);
	ret.x = cos_unit * a.x - sin_unit * a.y;
	ret.y = sin_unit * a.x + cos_unit * a.y;
	return (ret);
}