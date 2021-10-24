/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/10/22 22:04:48 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error\n");
	parse_mapfile(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3.d");
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_game(argc, argv, &data);
	return (EXIT_SUCCESS);
}