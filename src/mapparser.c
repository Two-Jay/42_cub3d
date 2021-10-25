/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:58:51 by jekim             #+#    #+#             */
/*   Updated: 2021/10/25 23:38:31 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*make_abspath(char *pwd, char *filepath, t_data *data)
{
	char	*ret;
	int		pwd_l;
	int		fp_l;

	pwd_l = ft_strlen(data->current_path);
	fp_l = ft_strlen(filepath);
	ret = (char *)ft_calloc(sizeof(char), pwd_l + fp_l);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, pwd, pwd_l + 1);
	while (*filepath == '.')
		filepath++;
	ft_strlcpy(ret + pwd_l, filepath, ft_strlen(filepath) + 1);
	ret[ft_strlen(ret)] = '\0';
	return (ret);
}

int	run_mapfile(char *filepath, t_data *data)
{
	int		path_l;
	int		fd_check;
	char	*target_path;

	path_l = ft_strlen(filepath);
	if (!ft_strequel(filepath + path_l - 4, ".cub"))
		return (-1);
	target_path = filepath;
	if (!ft_strncmp(filepath, "./", 2) || !ft_strncmp(filepath, "../", 3))
		target_path = make_abspath(data->current_path, filepath, data);
	if (!target_path)
		return (-1);
	fd_check = open(target_path, O_RDONLY, NULL);
	if (fd_check == -1)
		return (-1);
	return (fd_check);
}

int get_splited_len(char **splited)
{
	int ix;

	ix = -1;
	while (splited[++ix])
		;
	return (ix);
}

void free_splited(char **splited)
{
	int ix;

	ix = -1;
	while (splited[++ix])
		free(splited[ix]);
	free(splited);
	splited = NULL;
}

int	parse_imagepath(int fd, char **ptr, char *key)
{
	char	*line;
	char	**splited;
	int		line_check;

	line_check = ft_strgnl(fd, &line);
	if (line_check != 1)
		return (1);
	splited = ft_split(line, ' ');
	if (splited == NULL
		|| get_splited_len(splited) != 2
		|| !ft_strequel(splited[0], key))
		return (1);
	*ptr = ft_strdup(splited[1]);
	free_splited(splited);
	return (0);
}

int	parse_all_imagepaths(int map_fd, t_data *data)
{
	if (parse_imagepath(map_fd, &(data->file_data.NO_image_filename), "NO")
		|| parse_imagepath(map_fd, &(data->file_data.SO_image_filename), "SO")
		|| parse_imagepath(map_fd, &(data->file_data.WE_image_filename), "WE")
		|| parse_imagepath(map_fd, &(data->file_data.EA_image_filename), "EA"))
		return (1);
	return (0);
}

// int parse_RGBvalue(int fd, int *ptr, char *key)
// {
// 	return (0);
// }

// int	parse_all_RGBvalue(int map_fd, t_data *data)
// {
// 	return (0);
// }

// int	parse_mapdata(int map_fd, t_data *data)
// {
// 	return (0);
// }

int	parse_mapfile(char *filepath, t_data *data)
{
	int	map_fd;

	map_fd = run_mapfile(filepath, data);
	if (map_fd == -1)
		ft_strerr("Error : map file error\n");
	if (parse_all_imagepath(map_fd, data))
		return (close(map_fd) || ft_strerr("Error : invalid map data\n"));
	return (close(map_fd));
}