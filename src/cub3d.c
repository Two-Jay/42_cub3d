/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:59:38 by jekim             #+#    #+#             */
/*   Updated: 2022/03/11 04:13:48 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_imgs(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->parsed_data->imgs = (void **)ft_calloc(4, sizeof(void *));
	if (data->parsed_data->imgs == NULL)
		return (1);
	data->parsed_data->imgs[0] = mlx_png_file_to_image(data->window->mlx_ptr, data->parsed_data->EA_img_filepath, &w, &h);
	data->parsed_data->imgs[1] = mlx_png_file_to_image(data->window->mlx_ptr, data->parsed_data->WE_img_filepath, &w, &h);
	data->parsed_data->imgs[2] = mlx_png_file_to_image(data->window->mlx_ptr, data->parsed_data->SO_img_filepath, &w, &h);
	data->parsed_data->imgs[3] = mlx_png_file_to_image(data->window->mlx_ptr, data->parsed_data->NO_img_filepath, &w, &h);
	return (!data->parsed_data->imgs[0]
			|| !data->parsed_data->imgs[1]
			|| !data->parsed_data->imgs[2]
			|| !data->parsed_data->imgs[3]);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (init_game(argc, argv, env, &data) || init_imgs(data))
		ft_strerr("Error\n");
	render(data);
	set_hooks(data);
	mlx_loop(data->window->mlx_ptr);
	return (EXIT_SUCCESS);
}
