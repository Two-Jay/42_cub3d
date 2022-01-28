/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:58 by jekim             #+#    #+#             */
/*   Updated: 2022/01/28 00:30:40 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_hit_on_wall(t_map *map, t_intvec *map_index)
{
	return (map->mtrx[map_index->y][map_index->x] == 2);
}

int cast_ray(t_window *win, t_camera *cam, t_map *map)
{
	int 	i;

	i = -1;
	(void)win;
	(void)cam;
	while (++i < map->w)
	{
	}
    return (0);
}