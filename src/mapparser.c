/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:58:51 by jekim             #+#    #+#             */
/*   Updated: 2021/10/25 04:13:47 by jekim            ###   ########seoul.kr  */
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

int	parse_mapfile(char *filepath, t_data *data)
{
	int	map_fd;

	map_fd = run_mapfile(filepath, data);
	if (map_fd == -1)
		ft_strerr("Error : map file error\n");
	if (parse_imagepath(map_fd, data)
		|| parse_RGB(map_fd, data)
		|| parse_mapdata(map_fd, data))
		return (close(map_fd) || 1);
	return (close(map_fd));
}