/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:11:17 by jekim             #+#    #+#             */
/*   Updated: 2021/12/21 19:08:17 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = (char *)img->main_image_data + (y * img->size_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void put_line_orthos_x_from_top(t_data *data, int line_len, int x_position, int color)
{
	int ix;

	ix = 0;
	while (ix < line_len)
	{
		put_pixel_to_img(data->img, ix, x_position, color);
		ix++;
	}
}

void put_line_orthos_x_from_middle(t_data *data, int diameter, int x_position, int color)
{
	int ix;
	int jx;
	int limit;

	ix = data->window->resol_basic_y / 2;
	jx = data->window->resol_basic_y / 2 - 1;
	limit = diameter / 2;
	while (ix < limit)
	{
		put_pixel_to_img(data->img, ix, x_position, color);
		put_pixel_to_img(data->img, jx, x_position, color);
		ix++;
		jx--;
	}
}

void put_line_orthos_x_from_bottom(t_data *data, int line_len, int x_position, int color)
{
	int ix;

	ix = data->window->resol_basic_y;
	while (ix < line_len)
	{
		put_pixel_to_img(data->img, ix, x_position, color);
		ix--;
	}
}
