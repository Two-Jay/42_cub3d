/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:52:55 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 08:58:18 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_mapdata_lst	*append_mapdata_lst(char *line, t_mapdata_lst *lst)
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

static void get_width_and_height(t_data *data)
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

static char *malloc_mapdata_row(char *row, int width)
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
		ret[ix] = malloc_mapdata_row(lst->row, data->parsed_data.map_width);
		if (!ret[ix])
			return (1);
		lst = lst->next;
	}
	data->map_matrix = ret;
	return (0);
}