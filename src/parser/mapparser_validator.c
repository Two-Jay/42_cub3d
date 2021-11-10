/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:56:03 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 08:58:20 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static int check_mappoint(char **map, int ix, int jx)
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

static void count_space_type(char point, t_data *data)
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

static void set_count_bucket(t_data *data)
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
			if (ft_strchr(MAPTILE_CHARSET, map[ix][jx]))
			{
				count_space_type(map[ix][jx], data);
				checker = check_mappoint(map, ix, jx);
				if (checker)
					return (1);
			}
			jx++;
		}
		ix++;
	}
	return (0);
}

int validate_mapdata_object(t_data *data)
{
	if (data->parsed_data.N_cnt != 1
		|| data->parsed_data.space_cnt == 0)
		return (1);
	return (0);
}