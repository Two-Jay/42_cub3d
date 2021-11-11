/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:01 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 23:37:32 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void subcallback_press_esc(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
	exit(0);
}

int subcallback_press_move(int code, t_data *data)
{
	(void)data;
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
	t_data *data;

	data = (t_data *)dt;
	ft_printf("cub3d : pressed %x / key\n", code);
	if (code == KEY_W || code == KEY_A || code == KEY_S || code == KEY_D)
		subcallback_press_move(code, data);
	if (code == KEY_ESC)
		subcallback_press_esc(data);
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
	mlx_mouse_hook(data->window.win_ptr, &callback_mouse, "mouse");
	mlx_key_hook(data->window.win_ptr, &callback_key, (void *)data);
	mlx_expose_hook(data->window.win_ptr, &callback_expose, "expose");
	// mlx_loop_hook(data->mlx_ptr, &callback_hook, "loop");
}