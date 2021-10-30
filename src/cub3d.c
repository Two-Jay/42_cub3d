/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/10/24 16:25:39 by jekim            ###   ########.fr       */
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
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}