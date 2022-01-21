/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:11:17 by jekim             #+#    #+#             */
/*   Updated: 2022/01/14 17:01:21 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_over_window_xrange(int value, int window_x_range)
{
	return (value > window_x_range);
}

void put_pixel_img(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = (char *)img->data_addr + (y * img->size_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void put_yline_img(t_window *win, int line_l, int x_pos, int color)
{
	int ix;
	
	ix = 0;
	while (ix < line_l)
	{
		put_pixel_img(win->img, x_pos, ix, color);
		ix++;
	}
}