/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2021/10/25 03:42:45 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_strerr("Error\n");
	parse_mapfile(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "cub3.d");
}

void	get_current_path(char **env, t_data *data)
{
	int ix;

	ix = -1;
	while (env[++ix])
	{
		trs(env[ix]);
		if (ft_strncmp(env[ix], "PWD", 3) == 0)
			break ;
	}
	data->current_path = ft_strdup(env[ix] + 4);
	trs(data->current_path);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	get_current_path(env, &data);
	init_game(argc, argv, &data);
	return (EXIT_SUCCESS);
}