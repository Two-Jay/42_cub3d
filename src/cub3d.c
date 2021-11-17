/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/11/17 14:26:13 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_game(argc, argv, env, &data);
	print_mapmatrix((&data)->map_matrix, &data);
	render(&data);
	set_hooks(&data);
	mlx_loop((&data)->mlx_ptr);
	return (EXIT_SUCCESS);
}