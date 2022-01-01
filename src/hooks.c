/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:01 by jekim             #+#    #+#             */
/*   Updated: 2021/12/28 18:34:10 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int subcallback_exit(void *dt)
{
	t_data *data;

	data = (t_data *)dt;	
	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
	exit(0);
	return (0);
}

int subcallback_press_move(int code, void *dt)
{
	t_data *data;

	data = (t_data *)dt;
	if (code == KEY_W)
		printf ("cub3d : pressed W %d / key\n", code);
	if (code == KEY_A)
		printf ("cub3d : pressed A %d / key\n", code);
	if (code == KEY_S)
		printf ("cub3d : pressed S %d / key\n", code);
	if (code == KEY_D)
		printf ("cub3d : pressed D %d / key\n", code);
	return (0);
}

int callback_key(int code, void *dt)
{
	ft_printf("cub3d : pressed %x / key\n", code);
	if (code == KEY_W || code == KEY_A || code == KEY_S || code == KEY_D)
		subcallback_press_move(code, dt);
	if (code == KEY_ESC)
		subcallback_exit(dt);
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
	mlx_key_hook(data->window->win_ptr, &callback_key, (void *)data);
	mlx_expose_hook(data->window->win_ptr, &callback_expose, "expose");
	mlx_hook(data->window->win_ptr, 17, 0, &subcallback_exit, (void *)data);
	// mlx_loop_hook(data->mlx_ptr, &callback_hook, "loop");
}