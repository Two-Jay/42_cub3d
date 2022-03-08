/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:01 by jekim             #+#    #+#             */
/*   Updated: 2022/03/07 21:03:15 by jekim            ###   ########.fr       */
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
	static	int	frame;
	double	rot_speed;

	rot_speed = RAD * (frame * 0.3);
	if (code == KEY_W)
	{
		if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x + data->camera->dir.x * MOVE_SPEED)] != 2)
			data->camera->pos.x += data->camera->dir.x * MOVE_SPEED;
		if (data->map->mtrx[(int)(data->camera->pos.y + data->camera->dir.y * MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
			data->camera->pos.y += data->camera->dir.y * MOVE_SPEED;
	}
	if (code == KEY_A)
	{
		old_dirx = data->camera->dir.x;
		data->camera->dir.x = data->camera->dir.x * cos(rot_speed) - data->camera->dir.y * sin(rot_speed);
		data->camera->dir.y = old_dirx * sin(rot_speed) + data->camera->dir.y * cos(rot_speed);
		printf("%lf %lf\n", data->camera->dir.x, data->camera->dir.y);
		old_planex = data->camera->plain.x;
		data->camera->plain.x = data->camera->plain.x * cos(rot_speed) - data->camera->plain.y * sin(rot_speed);
		data->camera->plain.y = old_planex * sin(rot_speed) + data->camera->plain.y * cos(rot_speed);
		printf("%lf %lf\n", data->camera->plain.x, data->camera->plain.y);
	}
	if (code == KEY_S)
	{
		if (data->map->mtrx[(int)(data->camera->pos.y)][(int)(data->camera->pos.x - data->camera->dir.x * MOVE_SPEED)] != 2)
			data->camera->pos.x -= data->camera->dir.x * MOVE_SPEED;
		if (data->map->mtrx[(int)(data->camera->pos.y - data->camera->dir.y * MOVE_SPEED)][(int)(data->camera->pos.x)] != 2)
			data->camera->pos.y -= data->camera->dir.y * MOVE_SPEED;
	}
	if (code == KEY_D)
	{
		old_dirx = data->camera->dir.x;
		printf("%lf\n", cos(-rot_speed));
		data->camera->dir.x = data->camera->dir.x * cos(-rot_speed) - data->camera->dir.y * sin(-rot_speed);
		data->camera->dir.y = old_dirx * sin(-rot_speed) + data->camera->dir.y * cos(-rot_speed);
		// printf("%lf %lf\n", data->camera->dir.x, data->camera->dir.y);
		old_planex = data->camera->plain.x;
		data->camera->plain.x = data->camera->plain.x * cos(-rot_speed) - data->camera->plain.y * sin(-rot_speed);
		data->camera->plain.y = old_planex * sin(-rot_speed) + data->camera->plain.y * cos(-rot_speed);
		// printf("%lf %lf\n", data->camera->plain.x, data->camera->plain.y);
	}
	render(data);
	frame++;
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

int callback_mouse(int code, int x, int y, char *str)
{
	ft_printf("cub3d : clicked %x (%d,%d) / %s\n", code, x, y, str);
	return (0);
}

int callback_expose(char *str)
{
	ft_printf("cub3d : %s\n", str);
	return (0);
}

int callback_hook(char *str)
{
	ft_printf("cub3d : x / %s\n", str);
	return (0);
}

void set_hooks(t_data *data)
{
	mlx_mouse_hook(data->window->win_ptr, &callback_mouse, "mouse");
	//mlx_hook(data->window->win_ptr, 17, 0, &callback_key, data);
	mlx_hook(data->window->win_ptr, EVENT_KEY_PRESS, 0, &callback_key, (void *)data);
	//mlx_expose_hook(data->window->win_ptr, &callback_expose, "expose");
	//mlx_hook(data->window->win_ptr, 17, 0, &subcallback_exit, (void *)data);
	//mlx_loop_hook(data->window->mlx_ptr, render, data);
}
