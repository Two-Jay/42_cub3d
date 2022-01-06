/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2022/01/05 21:59:50 by jekim            ###   ########.fr       */
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

void draw_background(t_window *win, int f_color, int c_color)
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

int render(t_data *data)
{
	draw_background(data->window, data->parsed_data->F_RGB_value, data->parsed_data->C_RGB_value);
	return (0);
}
