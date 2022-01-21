/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:04:55 by jekim             #+#    #+#             */
/*   Updated: 2022/01/14 15:58:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	x = -1;
	while (++x < w)
	{
		y = -1;
		ret[x] = (t_pixel *)malloc(sizeof(t_pixel) * h);
		while (++y < h)
		{
			ret[x][y].distance = INFINITY;
			ret[x][y].color = (unsigned int *)((char *)img->data_addr
				+ img->size_length * y + img->bpp / 8 * x);
		}
	}
	return (ret);
}

int init_window(t_window *win)
{
	win->mlx_ptr = mlx_init();
	mlx_get_screen_size(win->mlx_ptr, &win->max_w, &win->max_h);
	get_basic_screen_size(&win->w, &win->h);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->w, win->h, "cub3.d");
	win->img->img_ptr = mlx_new_image(win->mlx_ptr, win->w, win->h);
	win->img->data_addr = (unsigned int *)mlx_get_data_addr(win->img->img_ptr,
			&win->img->bpp, &win->img->size_length, &win->img->endian);
	win->pixel = init_pixel(win->w, win->h, win->img);
	win->distance = 1 / tan(FOV / 2) * win->w / 2;
	win->ray = (t_ray *)ft_calloc(sizeof(t_ray), win->w);
	return (0);
}

int init_player(t_player *plyr)
{
	(void)plyr;	
	return (0);
}

int init_struct(t_data **data)
{
	(*data) = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		ft_strerr("data error\n");
	(*data)->parsed_data = (t_static *)ft_calloc(sizeof(t_static), 1);
	(*data)->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	(*data)->window = (t_window *)ft_calloc(sizeof(t_window), 1);
	(*data)->window->img = (t_img *)ft_calloc(sizeof(t_img), 1);
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
		|| init_window((*data)->window)
		|| init_player((*data)->player)
		|| parse_mapfile(argv[1], env, *data))
		ft_strerr("Error : the game can't be loaded");
	return (0);
}