/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:30 by gilee             #+#    #+#             */
/*   Updated: 2022/03/09 17:38:35 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->camera->dir.x;
	data->camera->dir.x = data->camera->dir.x * cos(-ROT_SPEED)
		- data->camera->dir.y * sin(-ROT_SPEED);
	data->camera->dir.y = old_dirx * sin(-ROT_SPEED)
		+ data->camera->dir.y * cos(-ROT_SPEED);
	old_planex = data->camera->plain.x;
	data->camera->plain.x = data->camera->plain.x * cos(-ROT_SPEED)
		- data->camera->plain.y * sin(-ROT_SPEED);
	data->camera->plain.y = old_planex * sin(-ROT_SPEED)
		+ data->camera->plain.y * cos(-ROT_SPEED);
}

void	turn_right(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->camera->dir.x;
	data->camera->dir.x = data->camera->dir.x * cos(ROT_SPEED)
		- data->camera->dir.y * sin(ROT_SPEED);
	data->camera->dir.y = old_dirx * sin(ROT_SPEED)
		+ data->camera->dir.y * cos(ROT_SPEED);
	old_planex = data->camera->plain.x;
	data->camera->plain.x = data->camera->plain.x * cos(ROT_SPEED)
		- data->camera->plain.y * sin(ROT_SPEED);
	data->camera->plain.y = old_planex * sin(ROT_SPEED)
		+ data->camera->plain.y * cos(ROT_SPEED);
}
