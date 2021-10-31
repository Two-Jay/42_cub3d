/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/10/30 16:33:14 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_game(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	parse_mapfile(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3.d");
	return (0);
}

int	get_current_path(char **env, t_data *data)
{
	int	ix;

	ix = 0;
	while (env[ix])
	{
		if (ft_strncmp(env[ix], "PWD", 3))
			ix++;
		else
			break ;
	}
	data->current_path = ft_strdup(env[ix] + 4);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	get_current_path(env, &data);
	init_game(argc, argv, &data);
	printf("it would be right!\n");
	// mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}