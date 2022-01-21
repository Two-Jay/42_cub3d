/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2022/01/17 18:06:58 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_background(t_window *win, unsigned int f_color, unsigned int c_color)
{
	int x;
	int y;
	t_pixel **pxlptr;
	
	pxlptr = win->pixel;
	y = -1;
	while (++y <= win->h / 2)
	{
		x = -1;
		while (++x < win->w)
			*(pxlptr[x][y].color) = f_color;
	}
	while (++y < win->h)
	{
		x = -1;
		while (++x < win->w)
			*(pxlptr[x][y].color) = c_color;
	}
}

int put_image(t_data *data)
{
	mlx_put_image_to_window(data->window->mlx_ptr,
								data->window->win_ptr,
								data->window->img->img_ptr, 0, 0);
	return (0);
}

int render(t_data *data, int **map)
{
	draw_background(data->window, data->parsed_data->F_RGB_value, data->parsed_data->C_RGB_value);
	if (put_image(data)
		|| cast_ray(data->window, data->player, map))
		return (ERROR_OCCURED);
	return (0);
}
