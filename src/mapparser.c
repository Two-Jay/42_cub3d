/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:58:51 by jekim             #+#    #+#             */
/*   Updated: 2021/11/10 17:16:23 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int skip_line(int fd, char **map_line, int *line_checker)
{
	int cnt;

	cnt = 0;
	*line_checker = ft_strgnl(fd, map_line);
	while ((int)ft_strlen(*map_line) == 0)
	{
		cnt++;
		if (cnt == 512)
			return (1);
		*line_checker = ft_strgnl(fd, map_line);
	}
	return (0);
}

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

void free_splited(char **splited)
{
	int ix;

	ix = -1;
	if (splited)
	{
		while (splited[++ix])
			free(splited[ix]);
		free(splited);
		splited = NULL;
	}
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

int	get_splited_len(char **splited)
{
	int	ix;

	ix = -1;
	while (splited[++ix])
		;
	return (ix);
}

char **get_and_check_splited(char *src, char c, int check_l, char *key)
{
	char **ret;

	ret = ft_split(src, c);
	if (ret == NULL
		|| get_splited_len(ret) != check_l
		|| !ft_strequel(ret[0], key))
	{
		free_splited(ret);
		return (NULL);
	}
	return (ret);
}

int	parse_imagepath(int fd, char **ptr, char *key)
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
	if (parse_imagepath(map_fd, &(data->parsed_data.NO_image_filename), "NO")
		|| parse_imagepath(map_fd, &(data->parsed_data.SO_image_filename), "SO")
		|| parse_imagepath(map_fd, &(data->parsed_data.WE_image_filename), "WE")
		|| parse_imagepath(map_fd, &(data->parsed_data.EA_image_filename), "EA"))
		return (1);
	return (0);
}

char	**get_RGBstr(int fd, char *key)
{
	char	*line;
	char	**splited;
	char	**rgb_arr;
	int		line_check;

	if (skip_line(fd, &line, &line_check))
		return (NULL);
	splited = get_and_check_splited(line, ' ', 2, key);
	if (splited == NULL)
		return (NULL);
	rgb_arr = ft_split(splited[1], ',');
	if (rgb_arr == NULL
		|| get_splited_len(rgb_arr) != 3)
		return (NULL);
	return (rgb_arr);
}

int	get_RGBvalue(char **parsed, t_data *data, char key)
{
	int	ix;
	int	ovf_flag;
	int	value;

	ix = 0;
	ovf_flag = 0;
	while (ix != 3 && parsed[ix])
	{
		if (ft_isable_strtonbr(parsed[ix]))
			return (1);
		value = ft_atoi_covf(parsed[ix], &ovf_flag);
		if (ovf_flag == 1 || value < 0 || value > 255)
			return (1);
		if (key == 'F')
			data->parsed_data.F_RGB[ix] = value;
		if (key == 'C')
			data->parsed_data.C_RGB[ix] = value;
		ix++;
	}
	return (0);
}

int	parse_all_RGBvalue(int map_fd, t_data *data)
{
	char	**rgb_parsed;

	data->parsed_data.F_RGB = (int *)malloc(sizeof(int) * 4);
	data->parsed_data.C_RGB = (int *)malloc(sizeof(int) * 4);
	if (!data->parsed_data.F_RGB || !data->parsed_data.C_RGB)
		return (1);
	data->parsed_data.F_RGB[3] = '\0';
	data->parsed_data.C_RGB[3] = '\0';
	rgb_parsed = get_RGBstr(map_fd, "F");
	if (rgb_parsed == NULL
		|| get_RGBvalue(rgb_parsed, data, 'F'))
		return (1);
	free_splited(rgb_parsed);
	rgb_parsed = get_RGBstr(map_fd, "C");
	if (rgb_parsed == NULL
		|| get_RGBvalue(rgb_parsed, data, 'C'))
		return (1);
	free_splited(rgb_parsed);
	return (0);
}

t_mapdata_lst	*append_mapdata_lst(char *line, t_mapdata_lst *lst)
{
	t_mapdata_lst *temp;
	
	temp = (t_mapdata_lst *)malloc(sizeof(t_mapdata_lst));
	if (!temp)
		return (NULL);
	temp->row = ft_strdup(line);
	lst->next = temp;
	free(line);
	return (temp);
}

int	parse_mapfile_rawdata(int map_fd, t_data *data)
{
	t_mapdata_lst	*lst;
	t_mapdata_lst	*head;
	int				line_check;
	char			*map_line;
	
	lst = (t_mapdata_lst *)malloc(sizeof(t_mapdata_lst));
	head = lst;
	if (skip_line(map_fd, &map_line, &line_check))
		return (1);
	while (line_check > 0)
	{
		lst = append_mapdata_lst(map_line, lst);
		if (!lst)
			return (1);
		line_check = ft_strgnl(map_fd, &map_line);
	}
	lst = append_mapdata_lst(map_line, lst);
	if (!lst)
		return (1);
	data->parsed_data.rawdata = head;
	return (0);
}

void get_width_and_height(t_data *data)
{
	t_mapdata_lst *lst;
	int	current_width;
	int max_width;
	int	height;

	current_width = 0;
	max_width = 0;
	height = 0;
	lst = data->parsed_data.rawdata->next;
	while (lst)
	{
		height++;
		current_width = ft_strlen(lst->row);
		if (max_width < current_width)
			max_width = current_width;
		lst = lst->next;
	}
	data->parsed_data.map_width = max_width;
	data->parsed_data.map_height = height;
}

char *malloc_row(char *row, int width)
{
	char *ret;
	int	ix;
	int	row_l;
	
	ix = 0;
	row_l = ft_strlen(row);
	ret = (char *)malloc(sizeof(char) * (width + 1));
	if (!ret)
		return (NULL);
	ret[width] = '\0';
	while (ix < width)
	{
		ret[ix] = ' ';
		ix++;
	}
	ft_memmove(ret, row, row_l);
	return (ret);
}

int convert_mapdata_matrix(t_data *data)
{
	char			**ret;
	t_mapdata_lst	*lst;
	int				ix;

	ix = -1;
	get_width_and_height(data);
	lst = data->parsed_data.rawdata->next;
	ret = (char **)malloc(sizeof(char *) * (data->parsed_data.map_height + 1));
	if (!ret)
		return (1);
	ret[data->parsed_data.map_height] = NULL;
	while (++ix < data->parsed_data.map_height)
	{
		ret[ix] = malloc_row(lst->row, data->parsed_data.map_width);
		if (!ret[ix])
			return (1);
		lst = lst->next;
	}
	data->map_matrix = ret;
	return (0);
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

int validate_mapdata_border(char **map, t_data *data)
{
	int ix;
	int height;
	int width;

	ix = 0;
	height = data->parsed_data.map_height;
	width = data->parsed_data.map_width;
	while (ix < width)
	{
		if (map[0][ix] == '0' || map[height - 1][ix] == '0')
			return (1);
		ix++;
	}
	ix = 0;
	while (ix < height)
	{
		if (map[ix][0] == '0' || map[ix][width] == '0')
			return (1);
		ix++;
	}
	return (0);
}

int check_mappoint(char **map, int ix, int jx)
{
	if (map[ix - 1][jx - 1] == ' '
		|| map[ix - 1][jx] == ' '
		|| map[ix - 1][jx + 1] == ' '
		|| map[ix][jx - 1] == ' '
		|| map[ix][jx + 1] == ' '
		|| map[ix + 1][jx - 1] == ' '
		|| map[ix + 1][jx] == ' '
		|| map[ix + 1][jx + 1] == ' ')
		return (1);
	return (0);
}

void count_space_type(char point, t_data *data)
{
	if (point == '0')
		data->parsed_data.space_cnt++;
	else if (point == 'N')
		data->parsed_data.N_cnt++;
	else if (point == 'S')
		data->parsed_data.S_cnt++;
	else if (point == 'E')
		data->parsed_data.E_cnt++;
	else if (point == 'W')
		data->parsed_data.W_cnt++;
}

void set_count_bucket(t_data *data)
{
	data->parsed_data.space_cnt = 0;
	data->parsed_data.N_cnt = 0;
	data->parsed_data.S_cnt = 0;
	data->parsed_data.E_cnt = 0;
	data->parsed_data.W_cnt = 0;
}

int validate_mapdata_space(char **map, t_data *data)
{
	int checker;
	int	ix;
	int jx;

	ix = 1;
	set_count_bucket(data);
	while (ix < data->parsed_data.map_height - 1)
	{
		jx = 1;
		while (jx < data->parsed_data.map_width - 1)
		{
			if (ft_strchr(SPACE_CHARSET, map[ix][jx]))
			{
				count_space_type(map[ix][jx], data);
				checker = check_mappoint(map, ix, jx);
			}
			if (checker)
				return (1);
			jx++;
		}
		ix++;
	}
	return (0);
}

int validate_mapdata_object(t_data *data)
{
	if (data->parsed_data.N_cnt == 0
		|| data->parsed_data.space_cnt == 0)
		return (1);
	return (0);
}

int	parse_mapfile(char *filepath, t_data *data)
{
	int	map_fd;

	map_fd = run_mapfile(filepath, data);
	if (map_fd == -1)
		ft_strerr("Error : map file error\n");
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