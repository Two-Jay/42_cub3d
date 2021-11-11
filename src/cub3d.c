/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 23:20:00 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_game(int argc, char **argv, char **env, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	parse_mapfile(argv[1], env, data);
	data->mlx_ptr = mlx_init();
	mlx_get_screen_size(data->mlx_ptr,
		&(data->window.resol_max_x), &(data->window.resol_max_y));
	data->window.win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3.d");
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_game(argc, argv, env, &data);
	print_mapmatrix((&data)->map_matrix);
	set_hooks(&data);
	mlx_loop((&data)->mlx_ptr);
	return (EXIT_SUCCESS);
}