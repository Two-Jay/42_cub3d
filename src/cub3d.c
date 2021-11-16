/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/11/16 19:17:30 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_game(argc, argv, env, &data);
	print_mapmatrix((&data)->map_matrix, &data);
	set_hooks(&data);
	draw();
	mlx_loop((&data)->mlx_ptr);
	return (EXIT_SUCCESS);
}