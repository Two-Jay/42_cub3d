/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/12/28 18:33:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	init_game(argc, argv, env, &data);
	print_mapmatrix(data->map_matrix, data);
	trp(data);
	render(data);
	set_hooks(data);
	mlx_loop(data->window->mlx_ptr);
	return (EXIT_SUCCESS);
}