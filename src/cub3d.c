/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/11/14 00:19:48 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


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

int init_game(int argc, char **argv, char **env, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	parse_mapfile(argv[1], env, data);
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

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_game(argc, argv, env, &data);
	print_mapmatrix((&data)->map_matrix, &data);
	set_hooks(&data);
	mlx_loop((&data)->mlx_ptr);
	return (EXIT_SUCCESS);
}