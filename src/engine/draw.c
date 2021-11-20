/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@42seoul.student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:11:17 by jekim             #+#    #+#             */
/*   Updated: 2021/11/21 02:03:10 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char *dst;

    dst = (char *)img->main_image_data + (y * img->size_length + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_test(t_data *data)
{
    int ix;
    int jx;

    ix = 0;
    while (ix < 100)
    {
        jx = 0;
        while (jx < 100)
        	put_pixel_to_img(data->img, ix, jx++, data->parsed_data->C_RGB_value);
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