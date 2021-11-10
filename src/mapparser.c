/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:58:51 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 08:19:50 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *get_abspath_prefix(char **env)
{
	int	ix;

	ix = 0;
	while (env[ix])
	{
		if (ft_strncmp(env[ix], "PWD", 3))
			ix++;
		else
			break ;
	}
	return (ft_strdup(env[ix] + 4));
}

char	*make_abspath(char *filepath, char **env)
{
	char	*ret;
	char	*abspath_prefix;
	int		pwd_l;
	int		fp_l;

	abspath_prefix = get_abspath_prefix(env);
	pwd_l = ft_strlen(abspath_prefix);
	fp_l = ft_strlen(filepath);
	ret = (char *)ft_calloc(sizeof(char), pwd_l + fp_l);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, abspath_prefix, pwd_l + 1);
	while (*filepath == '.')
		filepath++;
	ft_strlcpy(ret + pwd_l, filepath, ft_strlen(filepath) + 1);
	ret[ft_strlen(ret)] = '\0';
	return (ret);
}

int	run_mapfile(char *filepath, char **env)
{
	int		path_l;
	int		fd_check;
	char	*target_path;

	path_l = ft_strlen(filepath);
	if (!ft_strequel(filepath + path_l - 4, ".cub"))
		return (-1);
	target_path = filepath;
	if (!ft_strncmp(filepath, "./", 2) || !ft_strncmp(filepath, "../", 3))
		target_path = make_abspath(filepath, env);
	if (!target_path)
		return (-1);
	fd_check = open(target_path, O_RDONLY, NULL);
	trs(target_path);
	tri(fd_check);
	if (fd_check == -1)
		return (-1);
	return (fd_check);
}

int clear_mapdata_lst(t_mapdata_lst *lst)
{
	t_mapdata_lst *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}

int	parse_mapfile(char *filepath, char **env, t_data *data)
{
	int	map_fd;

	map_fd = run_mapfile(filepath, env);
	if (map_fd == -1)
		ft_strerr("Error : map file is not exist\n");
	if (parse_all_imagepaths(map_fd, data)
		|| parse_all_RGBvalue(map_fd, data)
		|| parse_mapfile_rawdata(map_fd, data)
		|| convert_mapdata_matrix(data)
		|| validate_mapdata_border(data->map_matrix, data)
		|| validate_mapdata_space(data->map_matrix, data)
		|| validate_mapdata_object(data)
		|| clear_mapdata_lst(data->parsed_data.rawdata))
		return (close(map_fd) || ft_strerr("Error : invalid map data\n"));
	return (close(map_fd));
}