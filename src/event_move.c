/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:03 by gilee             #+#    #+#             */
/*   Updated: 2022/03/09 18:10:03 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_front(t_data *data)
{
	if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x
			+ data->camera->dir.x * MOVE_SPEED)] != 2)
		data->camera->pos.x += data->camera->dir.x * MOVE_SPEED;
	if (data->map->mtrx[(int)(data->camera->pos.y + data->camera->dir.y
			* MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
		data->camera->pos.y += data->camera->dir.y * MOVE_SPEED;
}

void	move_back(t_data *data)
{
	if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x
				- data->camera->dir.x * MOVE_SPEED)] != 2)
		data->camera->pos.x -= data->camera->dir.x * MOVE_SPEED;
	if (data->map->mtrx[(int)(data->camera->pos.y - data->camera->dir.y
			* MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
		data->camera->pos.y -= data->camera->dir.y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	if (data->map->mtrx[(int)(data->camera->pos.y + data->camera->dir.y
			* MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
		data->camera->pos.y += data->camera->dir.y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	if (data->map->mtrx[(int)(data->camera->pos.y - data->camera->dir.y
			* MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
		data->camera->pos.y -= data->camera->dir.y * MOVE_SPEED;
}
