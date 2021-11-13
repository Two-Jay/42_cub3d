/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:04:55 by jekim             #+#    #+#             */
/*   Updated: 2021/11/14 01:05:21 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_struct_player(t_player *player)
{
	player->health = 100;
	player->armo = 15;
	player->speed = 10;
	return (0);
}

int get_basic_screen_size(t_data *data, int *x_ptr, int *y_ptr)
{
	int max_x;
	int max_y;

	max_x = data->window.resol_max_x;
	max_y = data->window.resol_max_y;
	if ((max_x / 16) == (max_y / 9))
	{
		*x_ptr = 960;
		*y_ptr = 540;
	}
	else
	{
		*x_ptr = 800;
		*y_ptr = 600;
	}
	return (0);
}

int init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	mlx_get_screen_size(data->mlx_ptr,
		&(data->window.resol_max_x), &(data->window.resol_max_y));
	get_basic_screen_size(data,
		&(data->window.resol_basic_x), &(data->window.resol_basic_y));
	data->window.win_ptr = mlx_new_window(data->mlx_ptr,
		data->window.resol_basic_x, data->window.resol_basic_x, "cub3.d");
	data->main_image_ptr = mlx_new_image(data->mlx_ptr, 
		data->window.resol_basic_x, data->window.resol_basic_y);
	return (0);
}

int init_game(int argc, char **argv, char **env, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	if (parse_mapfile(argv[1], env, data)
		|| init_struct_player(&(data->player))
		|| init_window(data))
		ft_strerr("Error : the game can't be loaded");
	return (0);
}