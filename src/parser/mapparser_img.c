/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:43:52 by jekim             #+#    #+#             */
/*   Updated: 2022/03/12 22:35:31 by jekim            ###   ########.fr       */
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

void set_texture_img_ptr(void *mlx_ptr, t_texture *texture_ptr, char *path)
{
	texture_ptr->img.img_ptr = mlx_png_file_to_image(mlx_ptr,
				path, &texture_ptr->w, &texture_ptr->h);
	texture_ptr->img.data_addr = mlx_get_data_addr(texture_ptr->img.img_ptr, 
				&texture_ptr->img.bpp, &texture_ptr->img.size_length, &texture_ptr->img.endian);	
}

int	load_imgs(void *mlx_ptr, t_map *map, t_static *parsed)
{
	map->txtr = (t_texture *)ft_calloc(sizeof(t_texture), 4);
	if (!map->txtr)
		return (ERROR_OCCURED);
	set_texture_img_ptr(mlx_ptr, &map->txtr[0], parsed->NO_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[1], parsed->SO_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[2], parsed->WE_img_filepath);
	set_texture_img_ptr(mlx_ptr, &map->txtr[3], parsed->EA_img_filepath);
	return (!map->txtr[0].img.img_ptr
				|| !map->txtr[1].img.img_ptr
				|| !map->txtr[2].img.img_ptr
				|| !map->txtr[3].img.img_ptr);
}