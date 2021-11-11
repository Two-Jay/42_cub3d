/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:01 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 20:28:08 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int callback_mouse(int code, int x, int y, char *str)
{
	ft_printf("cub3d : clicked %x (%d,%d) / %s\n", code, x, y, str);
	return (0);
}

int callback_key(int code, char *str)
{
	ft_printf("cub3d : pressed %x / %s\n", code, str);
	return (0);
}

int callback_expose(char *str)
{
	ft_printf("cub3d : %s", str);
	return (0);
}

int callback_hook(char *str)
{
	ft_printf("cub3d : %x / %s\n", str);
	return (0);
}

void set_hooks(t_data *data)
{
	mlx_mouse_hook(data->win_ptr, &callback_mouse, "mouse");
	mlx_key_hook(data->win_ptr, &callback_key, "key");
	mlx_expose_hook(data->win_ptr, &callback_expose, "expose");
	// mlx_loop_hook(data->mlx_ptr, &callback_hook, "loop");
}