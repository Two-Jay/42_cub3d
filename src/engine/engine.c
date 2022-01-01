/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2021/12/28 23:16:31 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_test(t_data *data)
{
	int ix;

	ix = 0;
	while (ix < 100)
	{
		put_yline_img(data->window, 100 + (ix * 2), ix, data->parsed_data->C_RGB_value);
		ix++;
	}
}

int render(t_data *data)
{
	data->window->img->main_image_data = (int *)mlx_get_data_addr(
											data->window->img->main_image_ptr,
											&data->window->img->bpp,
											&data->window->img->size_length,
											&data->window->img->endian);
	draw_test(data);
	mlx_put_image_to_window(data->window->mlx_ptr,
								data->window->win_ptr,
								data->window->img->main_image_ptr, 0, 0);
	return (0);
}