/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2022/03/13 15:43:25 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_mapmatrix(t_map *map)
{
	int ix;
	int jx;
	
	ix = 0;
	while (ix < map->h)
	{
		jx = 0;
		while (jx < map->w)
		{
			printf("%d", map->mtrx[ix][jx]);
			jx++;
		}
		printf("\n");
		ix++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (init_game(argc, argv, env, &data))
		ft_strerr("Error\n");
	render(data);
	print_mapmatrix(data->map);
	set_hooks(data);
	mlx_loop(data->window->mlx_ptr);
	return (EXIT_SUCCESS);
}
