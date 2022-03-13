/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:35:47 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 04:41:52 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_texture_vertical_line(t_window *win,
			t_texture_drawing_pack *tdp, int ray_index)
{
	double step;
	double texPos;
	int i;
	int texHeight;

	step = 1.0 * tdp->txtr_ptr->h / tdp->line_h;
	texPos = (tdp->yAxis_drawIndex.x - win->h / 2 + tdp->line_h / 2) * step;
	texHeight = tdp->txtr_ptr->h;
	i = tdp->yAxis_drawIndex.x;
	while (i < tdp->yAxis_drawIndex.y)
	{
		tdp->txtr_drawIdx.y = (int)texPos & (texHeight - 1);
		texPos += step;
		*(win->pixel[ray_index][i].color) = tdp->txtr_ptr->rowdata[texHeight *
				tdp->txtr_drawIdx.y + tdp->txtr_drawIdx.x];
		i++;
	}
}

int	is_hit_on_wall(int **map_mtrx, int y, int x)
{
	return (map_mtrx[y][x] == 2);
}

int	put_image_to_window(t_data *data)
{
	mlx_put_image_to_window(data->window->mlx_ptr,
		data->window->win_ptr,
		data->window->img->img_ptr, 0, 0);
	return (0);
}
