/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:52:55 by jekim             #+#    #+#             */
/*   Updated: 2022/03/14 02:32:15 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void define_spwan_direction(char position_value, int *direction_flag)
{
	if (position_value == 'N')
		*direction_flag |= SPWAN_NO;
	else if (position_value == 'S')
		*direction_flag |= SPWAN_SO;
	else if (position_value == 'E')
		*direction_flag |= SPWAN_EA;
	else if (position_value == 'W')
		*direction_flag |= SPWAN_WE;
}

static void	fill_maptile_row(int *arr, char *row, int size, int *dir_flag)
{
	int	ix;
	int	row_l;

	ix = 0;
	row_l = ft_strlen(row);
	while (ix < size)
	{
		if (row[ix] == '0')
			arr[ix] = 1;
		else if (row[ix] == '1')
			arr[ix] = 2;
		else if (row[ix] == 'N' || row[ix] == 'S'
			|| row[ix] == 'W' || row[ix] == 'E')
		{
			arr[ix] = 3;
			define_spwan_direction(row[ix], dir_flag);
		}
		ix++;
	}
}

static int	*malloc_mapdata_row(char *row, int width, int *direction_flag)
{
	int	*ret;
	int	ix;
	int	row_l;

	ix = 0;
	row_l = ft_strlen(row);
	ret = (int *)ft_calloc(sizeof(int), (width + 1));
	if (!ret)
		return (NULL);
	ret[width] = '\0';
	fill_maptile_row(ret, row, row_l, direction_flag);
	return (ret);
}

int	convert_mapdata_matrix(t_data *data)
{
	int				**ret;
	t_mapdata_lst	*lst;
	int				ix;

	ix = -1;
	lst = data->parsed_data->rawdata->next;
	ret = (int **)malloc(sizeof(int *) * (data->map->h + 1));
	if (!ret)
		return (1);
	ret[data->map->h] = NULL;
	while (++ix < data->map->h)
	{
		ret[ix] = malloc_mapdata_row(lst->row, data->map->w, 
					&data->camera->spwandir);
		if (!ret[ix])
			return (ERROR_OCCURED);
		lst = lst->next;
	}
	data->map->mtrx = ret;
	return (0);
}
