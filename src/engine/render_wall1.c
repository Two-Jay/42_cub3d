/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 04:45:02 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 17:31:37 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void init_yAxis_drawIndex(t_intvec *drawIndex,
                                        int window_h,
                                        int line_h)
{
	drawIndex->x = -line_h / 2 + window_h / 2;
	if (drawIndex->x < 0)
		drawIndex->x = 0;
	drawIndex->y = line_h / 2 + window_h / 2;
	if (drawIndex->y >= window_h)
		drawIndex->y = window_h - 1;
}

static t_texture *init_texture_to_draw(int side,
                                        t_ray* casted,
                                        t_texture *txtr_arr)
{
	if (side == 0 && casted->dir.x >= 0)
		return (&txtr_arr[EA]);
	if (side == 1 && casted->dir.y <= 0)
		return (&txtr_arr[NO]);
	if (side == 0 && casted->dir.x < 0)
		return (&txtr_arr[WE]);
	if (side == 1 && casted->dir.y > 0)
		return (&txtr_arr[SO]);
	return (0);
}

static void	init_x_index_texture(t_texture_drawing_pack *tdp,
									t_camera *cam,
									t_ray * casted)
{
	if (cam->side == 0)
		tdp->wall_x = cam->pos.y + casted->distance * casted->dir.y;
	else
		tdp->wall_x = cam->pos.x + casted->distance * casted->dir.x;
	tdp->wall_x -= floor(tdp->wall_x);
	tdp->txtr_drawIdx.x = (int)(tdp->wall_x * (double)(tdp->txtr_ptr->w));
	if (cam->side == 0 && casted->dir.x > 0)
		tdp->txtr_drawIdx.x = tdp->txtr_ptr->w - tdp->txtr_drawIdx.x - 1;
	if (cam->side == 1 && casted->dir.y < 0)
		tdp->txtr_drawIdx.x = tdp->txtr_ptr->w - tdp->txtr_drawIdx.x - 1;
}

static void	draw_texture_vertical_line(t_window *win,
			                                t_texture_drawing_pack *tdp,
                                            int ray_index)
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
		texPos += step;
		tdp->txtr_drawIdx.y = (int)texPos & (texHeight - 1);
		*(win->pixel[ray_index][i].color) = tdp->txtr_ptr->rowdata[texHeight *
				tdp->txtr_drawIdx.y + tdp->txtr_drawIdx.x];
		i++;
	}
}

void	draw_wall(t_data *data, int ray_index, t_ray *casted)
{
	t_texture_drawing_pack tdp;

	tdp.line_h = (int)(data->window->h / casted->distance);
	init_yAxis_drawIndex(&tdp.yAxis_drawIndex, data->window->h, tdp.line_h);
	tdp.txtr_ptr = init_texture_to_draw(data->camera->side,
                                            casted, data->map->txtr);
	init_x_index_texture(&tdp, data->camera, casted);
	draw_texture_vertical_line(data->window, &tdp, ray_index);
}