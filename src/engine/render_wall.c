/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:58 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 04:44:48 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_step_value(t_camera *cam, t_ray *ray)
{
	cam->deltaDist.x = fabs(1 / ray->dir.x);
	cam->deltaDist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		cam->step.x = -1;
		cam->sideDist.x = (cam->pos.x - cam->index.x) * cam->deltaDist.x;
	}
	else
	{
		cam->step.x = 1;
		cam->sideDist.x = (cam->index.x + 1.0 - cam->pos.x) * cam->deltaDist.x;
	}
	if (ray->dir.y < 0)
	{
		cam->step.y = -1;
		cam->sideDist.y = (cam->pos.y - cam->index.y) * cam->deltaDist.y;
	}
	else
	{
		cam->step.y = 1;
		cam->sideDist.y = (cam->index.y + 1.0 - cam->pos.y) * cam->deltaDist.y;
	}
}

double	deploy_ray_dda(t_camera *cam, t_ray *ray, int **map)
{
	while (1)
	{
		if (cam->sideDist.x < cam->sideDist.y)
		{
			cam->sideDist.x += cam->deltaDist.x;
			cam->index.x += cam->step.x;
			cam->side = 0;
		}
		else
		{
			cam->sideDist.y += cam->deltaDist.y;
			cam->index.y += cam->step.y;
			cam->side = 1;
		}
		if (is_hit_on_wall(map, cam->index.y, cam->index.x))
			break ;
	}
	return (define_ray_distance(cam, ray, cam->side));
}

int	render_wall(t_data *data)
{
	int			i;
	t_ray		*casted;

	i = -1;
	casted = NULL;
	while (++i < data->window->w)
	{
		init_camera_struct(data->camera, data->window->w, i);
		casted = &data->window->ray[i];
		init_ray_direction(casted, data->camera);
		init_step_value(data->camera, casted);
		casted->distance = deploy_ray_dda(data->camera,
				casted, data->map->mtrx);
		draw_wall(data, i, casted);
	}
	return (0);
}
