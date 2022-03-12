/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:43:52 by jekim             #+#    #+#             */
/*   Updated: 2022/03/12 15:46:03 by jekim            ###   ########.fr       */
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

int	load_imgs(void *mlx_ptr, t_map *map, t_static *parsed)
{
	map->txtr = (t_texture *)ft_calloc(sizeof(t_texture), 4);
	if (!map->txtr)
		return (ERROR_OCCURED);
	map->txtr[0].img.img_ptr = mlx_png_file_to_image(mlx_ptr,
				parsed->NO_img_filepath, &map->txtr[0].w, &map->txtr[0].h);
	map->txtr[1].img.img_ptr = mlx_png_file_to_image(mlx_ptr,
				parsed->SO_img_filepath, &map->txtr[1].w, &map->txtr[1].h);
	map->txtr[2].img.img_ptr = mlx_png_file_to_image(mlx_ptr,
				parsed->WE_img_filepath, &map->txtr[2].w, &map->txtr[2].h);
	map->txtr[3].img.img_ptr = mlx_png_file_to_image(mlx_ptr,
				parsed->EA_img_filepath, &map->txtr[3].w, &map->txtr[3].h);
	return (!map->txtr[0].img.img_ptr
				|| !map->txtr[1].img.img_ptr
				|| !map->txtr[2].img.img_ptr
				|| !map->txtr[3].img.img_ptr);
}