/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 17:42:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (init_game(argc, argv, env, &data))
		ft_strerr("Error\n");
	render(data);
	set_hooks(data);
	mlx_loop(data->window->mlx_ptr);
	return (EXIT_SUCCESS);
}
