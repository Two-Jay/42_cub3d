/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 08:20:15 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_game(int argc, char **argv, char **env, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	parse_mapfile(argv[1], env, data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3.d");
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_game(argc, argv, env, &data);
	print_mapmatrix((&data)->map_matrix);
	printf("it would be right!\n");
	// mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}