/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:56:03 by jekim             #+#    #+#             */
/*   Updated: 2021/11/14 00:38:43 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int validate_mapdata_border(int **map, t_data *data)
{
	int ix;
	int height;
	int width;

	ix = 0;
	height = data->parsed_data.map_height;
	width = data->parsed_data.map_width;
	while (ix < width)
	{
		if (map[0][ix] == 1 || map[height - 1][ix] == 1)
			return (1);
		ix++;
	}
	ix = 0;
	while (ix < height)
	{
		if (map[ix][0] == 1 || map[ix][width - 1] == 1)
			return (1);
		ix++;
	}
	return (0);
}

static int check_mappoint(int **map, int ix, int jx)
{
	if (map[ix - 1][jx - 1] == 0
		|| map[ix - 1][jx] == 0
		|| map[ix - 1][jx + 1] == 0
		|| map[ix][jx - 1] == 0
		|| map[ix][jx + 1] == 0
		|| map[ix + 1][jx - 1] == 0
		|| map[ix + 1][jx] == 0
		|| map[ix + 1][jx + 1] == 0)
		return (1);
	return (0);
}

static void count_space_type(int point, t_data *data)
{
	if (point == 1)
		data->parsed_data.space_cnt++;
	else if (point == 3)
		data->parsed_data.N_cnt++;
	else if (point == 4)
		data->parsed_data.S_cnt++;
	else if (point == 5)
		data->parsed_data.E_cnt++;
	else if (point == 6)
		data->parsed_data.W_cnt++;
}

static void set_count_bucket(t_data *data)
{
	data->parsed_data.space_cnt = 0;
	data->parsed_data.N_cnt = 0;
	data->parsed_data.S_cnt = 0;
	data->parsed_data.E_cnt = 0;
	data->parsed_data.W_cnt = 0;
}

int validate_mapdata_space(int **map, t_data *data)
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
			count_space_type(map[ix][jx], data);
			if (map[ix][jx] != 0 && map[ix][jx] != 2) 
				checker = check_mappoint(map, ix, jx);
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
	tri(data->parsed_data.space_cnt);
	tri(data->parsed_data.N_cnt);
	tri(data->parsed_data.S_cnt);
	tri(data->parsed_data.E_cnt);
	tri(data->parsed_data.W_cnt);
	if (data->parsed_data.N_cnt != 1
		|| data->parsed_data.space_cnt == 0)
		return (1);
	return (0);
}