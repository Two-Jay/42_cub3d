/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:58 by jekim             #+#    #+#             */
/*   Updated: 2022/01/30 20:29:17 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_cam(t_camera *cam, int window_width, int ray_index)
{
	cam->dir.x = -1;
	cam->dir.y = 0;
	cam->plain.x = 0;
	cam->plain.y = 0.66;
	cam->time = 0;
	cam->old_time = 0;
	cam->camera_x = 2 * ray_index / (double)window_width - 1;
	cam->index.x = (int)cam->pos.x;
	cam->index.y = (int)cam->pos.y;
}

void init_step_value(t_camera *cam, t_ray *ray)
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

void init_ray_direction(t_ray *ray, t_camera *cam)
{
	ray->dir.x = cam->dir.x + cam->plain.x * cam->camera_x;
	ray->dir.y = cam->dir.y + cam->plain.y * cam->camera_x;
}

double define_ray_distance(t_camera *cam, t_ray *ray, int side)
{
	if (side == 0)
		return ((cam->index.x - cam->pos.x + (1 - cam->step.x) / 2) / ray->dir.x);
	else
		return ((cam->index.y - cam->pos.y + (1 - cam->step.y) / 2) / ray->dir.y);
}

double deploy_ray_dda(t_camera *cam, t_ray *ray, int **map)
{
	int side;
	
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

void draw_wall(double ray_dist, t_window *win, int ray_index)
{
	int 		line_h;
	t_intvec 	drawpoint;

	line_h = (int)(win->h/ ray_dist);
	drawpoint.x = -line_h / 2 + win->h / 2;
	if (drawpoint.x < 0)
		drawpoint.x = 0; 
	drawpoint.y = line_h / 2 + win->h / 2;
	if (drawpoint.y >= win->h)
		drawpoint.y = win->h - 1;
	put_pixel_vertical_line(win, &drawpoint, ray_index);
}

int render_wall(t_window *win, t_camera *cam, t_map *map)
{
	int 	i;
	t_ray	*casted;
	
	i = -1;
	casted = NULL;
	while (++i < win->w)
	{
		casted = &win->ray[i];
		init_cam(cam, win->w, i);
		init_ray_direction(casted, cam);
		init_step_value(cam, casted);
		casted->distance = deploy_ray_dda(cam, casted, map->mtrx);
		draw_wall(casted->distance, win, i);
	}
    return (0);
}