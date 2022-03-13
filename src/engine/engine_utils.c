/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:04:19 by gilee             #+#    #+#             */
/*   Updated: 2022/03/14 01:32:42 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray_direction(t_ray *ray, t_camera *cam)
{
	ray->dir.x = cam->dir.x + cam->plain.x * cam->camera_x;
	ray->dir.y = cam->dir.y + cam->plain.y * cam->camera_x;
}

double	define_ray_distance(t_camera *cam, t_ray *ray, int side)
{
	if (side == 0)
		return ((cam->index.x - cam->pos.x + (1 - cam->step.x) / 2)
			/ ray->dir.x);
	else
		return ((cam->index.y - cam->pos.y + (1 - cam->step.y) / 2)
			/ ray->dir.y);
}

void 	init_camera_vectors_WE(t_vec *dirvec, t_vec *planevec, int *direction_flag)
{
	if (*direction_flag & SPWAN_WE)
	{
		dirvec->x = -1;
		dirvec->y = 0;
		planevec->x = 0;
		planevec->y = -0.66;
	}
	if (*direction_flag & SPWAN_EA)
	{
		dirvec->x = 1;
		dirvec->y = 0;
		planevec->x = 0;
		planevec->y = 0.66;
	}
	*direction_flag = 0;
}


void 	init_camera_vectors_NS(t_vec *dirvec, t_vec *planevec, int *direction_flag)
{
	if (*direction_flag & SPWAN_NO)
	{
		dirvec->x = 0;
		dirvec->y = -1;
		planevec->x = 0.66;
		planevec->y = 0;
	}
	if (*direction_flag & SPWAN_SO)
	{
		dirvec->x = 0;
		dirvec->y = 1;
		planevec->x = -0.66;
		planevec->y = 0;
	}
	*direction_flag = 0;
}

void	init_camera_struct(t_camera *cam, int window_w, int ray_index)
{
	if (cam->spwandir != 0)
	{
		if (cam->spwandir & SPWAN_NO || cam->spwandir & SPWAN_SO)
			init_camera_vectors_NS(&cam->dir, &cam->plain, &cam->spwandir);
		if (cam->spwandir & SPWAN_WE || cam->spwandir & SPWAN_EA)
			init_camera_vectors_WE(&cam->dir, &cam->plain, &cam->spwandir);
		cam->side = 0;
	}
	cam->camera_x = 2 * ray_index / (double)window_w - 1;
	cam->index.x = (int)cam->pos.x;
	cam->index.y = (int)cam->pos.y;
}
