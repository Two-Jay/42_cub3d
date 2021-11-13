/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:52:55 by jekim             #+#    #+#             */
/*   Updated: 2021/11/14 00:55:06 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void fill_maptile_row(int *arr, char *row, int size)
{
	int ix;

	ix = 0;
	while (ix < size)
	{
		if (row[ix] == ' ')
			arr[ix] = 0;
		if (row[ix] == '0')
			arr[ix] = 1;
		else if (row[ix] == '1')
			arr[ix] = 2;
		else if (row[ix] == 'N')
			arr[ix] = 3;
		else if (row[ix] == 'S')
			arr[ix] = 4;
		ix++;
	}
}

static int *malloc_mapdata_row(char *row, int width)
{
	int *ret;
	int	ix;
	int	row_l;
	
	ix = 0;
	row_l = ft_strlen(row);
	ret = (int *)malloc(sizeof(int) * (width + 1));
	if (!ret)
		return (NULL);
	ret[width] = '\0';
	fill_maptile_row(ret, row, row_l);
	return (ret);
}

int convert_mapdata_matrix(t_data *data)
{
	int				**ret;
	t_mapdata_lst	*lst;
	int				ix;

	ix = -1;
	get_width_and_height(data);
	lst = data->parsed_data.rawdata->next;
	ret = (int **)malloc(sizeof(int *) * (data->parsed_data.map_height + 1));
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