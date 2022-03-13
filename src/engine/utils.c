/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:35:47 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 02:54:34 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// needed fix to load texture here
void	put_pixel_vertical_line(t_window *win, t_intvec *point, int ray_index)
{
	int		i;
	t_pixel	**pxlptr;

	i = point->x;
	pxlptr = win->pixel;
	while (i < point->y)
		*(pxlptr[ray_index][i++].color) = RGB_RED;
}

int		assign_texNum(int side, t_ray* casted)
{
	if (side == 0 && casted->dir.x > 0)
		return (NO);
	if (side == 1 && casted->dir.y < 0)
		return (SO);
	if (side == 0 && casted->dir.x < 0)
		return (WE);
	if (side == 1 && casted->dir.y > 0)
		return (EA);
	return (0);
}

void	put_texture_vertical_line(t_data *data, t_ray *casted, int line_h, t_intvec *drawpoint, int ray_index)
{
	int texNum;
	t_intvec texIndex;
	double wallX;

	texNum = assign_texNum(data->camera->side, casted);
	if (data->camera->side == 0)
		wallX = data->camera->pos.y + casted->distance + casted->dir.y;
	else
		wallX = data->camera->pos.x + casted->distance + casted->dir.x;
	wallX -= floor(wallX);
	texIndex.x = (int)(wallX * (double)(data->map->txtr[texNum].w));
	if (data->camera->side == 0 && casted->dir.x > 0)
		texIndex.x = data->map->txtr[texNum].w - texIndex.x - 1;
	if (data->camera->side == 1 && casted->dir.y < 0)
		texIndex.x = data->map->txtr[texNum].w - texIndex.x - 1;

	double step = 1.0 * data->map->txtr[texNum].h / line_h;
	double texPos = (drawpoint->x / data->window->h) * step;

	int i;
	int texHeight = data->map->txtr[texNum].h;
	unsigned int color;

	i = drawpoint->x;
	while (i < drawpoint->y)
	{
		texIndex.y = (int)texPos & (texHeight - 1);
		texPos += step;
		color = data->map->txtr[texNum].rowdata[texHeight * texIndex.y + texIndex.x];
		*(data->window->pixel[ray_index][i].color) = color;
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
