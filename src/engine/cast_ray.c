/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:58 by jekim             #+#    #+#             */
/*   Updated: 2022/01/23 17:14:07 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void set_ray_direction(t_window *win, t_player *plyr, int index)
{
	plyr->camera_x = 2 / index * (double)win->w - 1;
	win->ray[index].dir.x = plyr->dir.x + plyr->plain.x * plyr->camera_x;
	win->ray[index].dir.y = plyr->dir.y + plyr->plain.y * plyr->camera_x;
}

void set_map_idx(t_intvec *map, t_player *plyr)
{
	map->x = (int)plyr->pos.x;
	map->y = (int)plyr->pos.y;
}

int is_hit_on_wall(t_map *map, t_intvec *map_index)
{
	return (map->mtrx[map_index->x][map_index->y] == 2);
}

void set_distvec_and_step(t_intvec *map, t_intvec *step, t_player *plyr, t_ray *ray)
{
	ray->deltaDist.x = fabs(1 / ray->dir.x);
	ray->deltaDist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		step->x = -1;
		ray->sideDist.x = (plyr->pos.x - map->x) * ray->deltaDist.x;
	}
	else
	{
		step->x = 1;
		ray->sideDist.x = (map->x + 1.0 - plyr->pos.x) * ray->deltaDist.x;
	}
	if (ray->dir.y < 0)
	{
		step->y = -1;
		ray->sideDist.y = (plyr->pos.y - map->y) * ray->deltaDist.y;
	}
	else
	{
		step->y = 1;
		ray->sideDist.y = (map->y + 1.0 - plyr->pos.y) * ray->deltaDist.y;
	}
}

void get_distance_by_dda(t_intvec *map_index, t_intvec *step, t_ray *ray, t_map *map)
{
	int hit;
	int side;
	
	hit = 0;
	while (!hit)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			map_index->x += step->x;
			side = 0;
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			map_index->y += step->y;
			side = 1;
		}
		print_mapmatrix(map);
		printf("x : %d y :%d\n", map_index->x, map_index->y);
		if (is_hit_on_wall(map, map_index))
			hit = 1;
	}
}

void send_ray(t_player *plyr, t_window *win, int index, t_map *map)
{
	t_intvec map_idx;
	t_intvec step;
	
	set_map_idx(&map_idx, plyr);
	set_distvec_and_step(&map_idx, &step, plyr, &(win->ray[index]));
	get_distance_by_dda(&map_idx, &step, &(win->ray[index]), map);
}

int cast_ray(t_window *win, t_player *plyr, t_map *map)
{
	int i;
	
	i = -1;
	while (++i < win->w)
	{
        set_ray_direction(win, plyr, i);
		send_ray(plyr, win, i, map);
	}
    return (0);
}