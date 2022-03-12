/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:35:47 by jekim             #+#    #+#             */
/*   Updated: 2022/03/12 21:24:04 by jekim            ###   ########.fr       */
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

void	put_texture_vertical_line(t_map *map, t_camera *cam, t_ray *casted)
{
	// int texNum = *(map->mtrx[cam->index.y, cam->index.y]) - 2;
	int texNum;
	int texX;
	double wallX;

	texNum = 0;
	if (cam->side == 0)
		wallX = cam->pos.y + casted->distance + casted->dir.y;
	else
		wallX = cam->pos.x + casted->distance + casted->dir.x;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)(map->txtr[texNum].w));
	if (cam->side == 0 && casted->dir.x > 0)
		texX = map->txtr[texNum].w - texX - 1;
	if (cam->side == 1 && casted->dir.y < 0)
		texX = map->txtr[texNum].w - texX - 1;
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
