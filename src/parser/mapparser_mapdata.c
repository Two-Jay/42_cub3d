/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:52:55 by jekim             #+#    #+#             */
/*   Updated: 2021/11/16 18:53:54 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void fill_maptile_row(int *arr, char *row, int size)
{
	int ix;
	int row_l;

	ix = 0;
	row_l = ft_strlen(row);
	while (ix < size)
	{
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
	ret = (int *)ft_calloc(sizeof(int), (width + 1));
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