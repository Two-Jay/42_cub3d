/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2021/12/21 19:08:12 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_test(t_data *data)
{
	int ix;

	ix = 0;
	while (ix < 100)
	{
		put_pixel_to_img(data->img, ix, 10, data->parsed_data->C_RGB_value);
		ix++;
	}
}

int render(t_data *data)
{
	data->img->main_image_data = (int *)mlx_get_data_addr(
											data->img->main_image_ptr,
											&data->img->bpp,
											&data->img->size_length,
											&data->img->endian);
	draw_test(data);
	mlx_put_image_to_window(data->mlx_ptr,
								data->window->win_ptr,
								data->img->main_image_ptr, 0, 0);
	return (0);
}