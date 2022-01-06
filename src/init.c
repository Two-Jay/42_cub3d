/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:04:55 by jekim             #+#    #+#             */
/*   Updated: 2022/01/06 17:17:21 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_struct_player(t_player *player)
{
	player->health = 100;
	player->armo = 15;
	player->speed = 10;
	return (0);
}

int get_basic_screen_size(int *x_ptr, int *y_ptr)
{
	*x_ptr = 800;
	*y_ptr = 640;
	return (0);
}

t_pixel **init_pixel(int w, int h, t_img *img)
{
	t_pixel **ret;
	int		x;
	int		y;

	ret = (t_pixel **)malloc(sizeof(t_pixel *) * w);
	y = -1;
	while (++y < w)
	{
		ret[y] = (t_pixel *)malloc(sizeof(t_pixel) * h);
		x = -1;
		while (++x < h)
		{
			ret[y][x].distance = INFINITY;
			ret[y][x].color = (unsigned int *)(char *)img->data_addr
				+ (img->size_length * y) + (img->bpp / 8 * x);
		}
	}
	return (ret);
}

int init_window(t_window *win)
{
	win->mlx_ptr = mlx_init();
	mlx_get_screen_size(win->mlx_ptr,
		&win->max_w, &win->max_h);
	get_basic_screen_size(&win->w, &win->h);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->w, win->w, "cub3.d");
	win->img->img_ptr = mlx_new_image(win->mlx_ptr, win->w, win->h);
	win->distance = 1 / tan(FOV / 2) * win->w / 2;
	win->img->data_addr = (unsigned int *)mlx_get_data_addr(win->img->img_ptr,
			&win->img->bpp, &win->img->size_length, &win->img->endian);
	win->pixel = init_pixel(win->w, win->h, win->img);
	tri(win->w);
	tri(win->h);
	return (0);
}

int init_struct(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_strerr("data error\n");
	(*data)->parsed_data = (t_static *)malloc(sizeof(t_static));
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	(*data)->window = (t_window *)malloc(sizeof(t_window));
	(*data)->window->img = (t_img *)malloc(sizeof(t_img));
	if ((*data)->parsed_data == NULL
		|| (*data)->player == NULL
		|| (*data)->window == NULL
		|| (*data)->window->img == NULL)
		ft_strerr("data error\n");
	return (0);
}

int init_game(int argc, char **argv, char **env, t_data **data)
{
	if (argc != 2)
		ft_strerr("Error : no parameter\n");
	if (init_struct(data)
		|| init_struct_player((*data)->player)
		|| init_window((*data)->window)
		|| parse_mapfile(argv[1], env, *data))
		ft_strerr("Error : the game can't be loaded");
	return (0);
}