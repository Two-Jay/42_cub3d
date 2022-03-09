/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:01 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 02:37:07 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int callback_exit(void *dt)
{
	t_data *data;

	data = (t_data *)dt;	
	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
	exit(0);
}

int subcallback_press_move(int code, t_data *data)
{
	double	old_dirx;
	double	old_planex;

	if (code == KEY_W)
	{
		if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x + data->camera->dir.x * MOVE_SPEED)] != 2)
			data->camera->pos.x += data->camera->dir.x * MOVE_SPEED;
		if (data->map->mtrx[(int)(data->camera->pos.y + data->camera->dir.y * MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
			data->camera->pos.y += data->camera->dir.y * MOVE_SPEED;
	}
	if (code == KEY_D)
	{
		old_dirx = data->camera->dir.x;
		data->camera->dir.x = data->camera->dir.x * cos(ROT_SPEED) - data->camera->dir.y * sin(ROT_SPEED);
		data->camera->dir.y = old_dirx * sin(ROT_SPEED) + data->camera->dir.y * cos(ROT_SPEED);
		old_planex = data->camera->plain.x;
		data->camera->plain.x = data->camera->plain.x * cos(ROT_SPEED) - data->camera->plain.y * sin(ROT_SPEED);
		data->camera->plain.y = old_planex * sin(ROT_SPEED) + data->camera->plain.y * cos(ROT_SPEED);
	}
	if (code == KEY_S)
	{
		if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x - data->camera->dir.x * MOVE_SPEED)] != 2)
			data->camera->pos.x -= data->camera->dir.x * MOVE_SPEED;
		if (data->map->mtrx[(int)(data->camera->pos.y - data->camera->dir.y * MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
			data->camera->pos.y -= data->camera->dir.y * MOVE_SPEED;
	}
	if (code == KEY_A)
	{
		old_dirx = data->camera->dir.x;
		data->camera->dir.x = data->camera->dir.x * cos(-ROT_SPEED) - data->camera->dir.y * sin(-ROT_SPEED);
		data->camera->dir.y = old_dirx * sin(-ROT_SPEED) + data->camera->dir.y * cos(-ROT_SPEED);
		old_planex = data->camera->plain.x;
		data->camera->plain.x = data->camera->plain.x * cos(-ROT_SPEED) - data->camera->plain.y * sin(-ROT_SPEED);
		data->camera->plain.y = old_planex * sin(-ROT_SPEED) + data->camera->plain.y * cos(-ROT_SPEED);
	}
	render(data);
	return (0);
}

int callback_key(int code, t_data *data)
{
	if (code == KEY_W || code == KEY_A || code == KEY_S || code == KEY_D)
		subcallback_press_move(code, data);
	if (code == KEY_ESC)
		callback_exit(data);
	return (0);
}

void set_hooks(t_data *data)
{
	mlx_hook(data->window->win_ptr, EVENT_KEY_PRESS, 0, &callback_key, (void *)data);
}
