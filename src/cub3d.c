/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2022/01/17 18:06:06 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (init_game(argc, argv, env, &data))
		ft_strerr("Error\n");
	render(data, data->map_matrix);
	print_mapmatrix(data->map_matrix, data);
	set_hooks(data);
	mlx_loop(data->window->mlx_ptr);
	return (EXIT_SUCCESS);
}