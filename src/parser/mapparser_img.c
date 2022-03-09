/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@42seoul.student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:43:52 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 17:17:49 by gilee            ###   ########.fr       */
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
		return (1);
	splited = get_and_check_splited(line, ' ', 2, key);
	if (splited == NULL)
		return (1);
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
		return (1);
	return (0);
}
