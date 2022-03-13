/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:43:52 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 02:25:50 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_imagepath(int fd, char **ptr, char *key)
{
	char	*line;
	char	**splited;
	int		line_check;

	if (skip_line(fd, &line, &line_check)
		|| (line_check != 1 && !ft_strequel(key, "NO")))
		return (ERROR_OCCURED);
	splited = get_and_check_splited(line, ' ', 2, key);
	if (splited == NULL)
		return (ERROR_OCCURED);
	*ptr = ft_strdup(splited[1]);
	free_splited(splited);
	return (0);
}

int	parse_all_imagepaths(int map_fd, t_data *data)
{
	if (parse_imagepath(map_fd, &data->parsed_data->NO_img_filepath, "NO")
		|| parse_imagepath(map_fd, &data->parsed_data->SO_img_filepath, "SO")
		|| parse_imagepath(map_fd, &data->parsed_data->WE_img_filepath, "WE")
		|| parse_imagepath(map_fd, &data->parsed_data->EA_img_filepath, "EA"))
		return (ERROR_OCCURED);
	return (0);
}

void set_texture_img_ptr(void *mlx_ptr, t_texture *txtr, char *path)
{
	int i;
	int j;

	txtr->img.img_ptr = mlx_png_file_to_image(mlx_ptr, path,
				&txtr->w, &txtr->h);
	txtr->img.data_addr = (unsigned int *)mlx_get_data_addr(txtr->img.img_ptr, 
				&txtr->img.bpp, &txtr->img.size_length, &txtr->img.endian);
	txtr->rowdata = (unsigned int *)ft_calloc(sizeof(int), txtr->h * txtr->w);
	i = -1;	
	while(++i < txtr->h)
	{
		j = -1;
		while (++j < txtr->w)
		{
			txtr->rowdata[txtr->w * i + j]
				= txtr->img.data_addr[txtr->w * i + j];
		}
	}
}

int img_loadchecker(t_texture *txtr)
{
	return (!txtr->img.img_ptr || !txtr->rowdata);
}

int	load_imgs(void *mlx_ptr, t_map *map, t_static *parsed)
{
	map->txtr = (t_texture *)ft_calloc(sizeof(t_texture), 4);
	if (!map->txtr)
		return (ERROR_OCCURED);
	set_texture_img_ptr(mlx_ptr, &map->txtr[NO], parsed->NO_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[SO], parsed->SO_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[WE], parsed->WE_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[EA], parsed->EA_img_filepath);
	return (img_loadchecker(&map->txtr[NO])
				|| img_loadchecker(&map->txtr[SO])
				|| img_loadchecker(&map->txtr[WE])
				|| img_loadchecker(&map->txtr[EA]));
}