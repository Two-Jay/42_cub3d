/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:04:19 by gilee             #+#    #+#             */
/*   Updated: 2022/03/12 16:41:01 by jekim            ###   ########.fr       */
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

void	init_camera_dir(t_camera *cam)
{
	cam->dir.x = 1;
	cam->dir.y = 0;
	cam->plain.x = 0;
	cam->plain.y = 0.66;
	cam->time = 0;
	cam->old_time = 0;
	cam->side = 0;
}

void	init_cameara_index(t_camera *cam, int window_w, int ray_index)
{
	cam->camera_x = 2 * ray_index / (double)window_w - 1;
	cam->index.x = (int)cam->pos.x;
	cam->index.y = (int)cam->pos.y;
}
