/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:58 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 17:05:10 by gilee            ###   ########.fr       */
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
	int	side;

	while (TRUE)
	{
		if (cam->sideDist.x < cam->sideDist.y)
		{
			cam->sideDist.x += cam->deltaDist.x;
			cam->index.x += cam->step.x;
			side = 0;
		}
		else
		{
			cam->sideDist.y += cam->deltaDist.y;
			cam->index.y += cam->step.y;
			side = 1;
		}
		if (is_hit_on_wall(map, cam->index.y, cam->index.x))
			break ;
	}
	return (define_ray_distance(cam, ray, side));
}

void	draw_wall(double ray_dist, t_window *win, int ray_index)
{
	int			line_h;
	t_intvec	drawpoint;

	line_h = (int)(win->h / ray_dist);
	drawpoint.x = -line_h / 2 + win->h / 2;
	if (drawpoint.x < 0)
		drawpoint.x = 0;
	drawpoint.y = line_h / 2 + win->h / 2;
	if (drawpoint.y >= win->h)
		drawpoint.y = win->h - 1;
	put_pixel_vertical_line(win, &drawpoint, ray_index);
}

int	render_wall(t_window *win, t_camera *cam, t_map *map)
{
	int			i;
	static int	not_first;
	t_ray		*casted;

	i = -1;
	casted = NULL;
	while (++i < win->w)
	{
		init_cameara_index(cam, win->w, i);
		casted = &win->ray[i];
		if (not_first != 1)
			init_camera_dir(cam);
		init_ray_direction(casted, cam);
		init_step_value(cam, casted);
		casted->distance = deploy_ray_dda(cam, casted, map->mtrx);
		draw_wall(casted->distance, win, i);
	}
	not_first = 1;
	return (0);
}
