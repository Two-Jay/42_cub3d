/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:57:04 by jekim             #+#    #+#             */
/*   Updated: 2022/01/14 13:48:57 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		data->parsed_data->space_cnt++;
	else if (point == 3)
		data->parsed_data->N_cnt++;
	else if (point == 4)
		data->parsed_data->S_cnt++;
	else if (point == 5)
		data->parsed_data->E_cnt++;
	else if (point == 6)
		data->parsed_data->W_cnt++;
}

static void set_count_bucket(t_data *data)
{
	data->parsed_data->space_cnt = 0;
	data->parsed_data->N_cnt = 0;
	data->parsed_data->S_cnt = 0;
	data->parsed_data->E_cnt = 0;
	data->parsed_data->W_cnt = 0;
}

int validate_mapdata_space(int **map, t_data *data)
{
	int checker;
	int	ix;
	int jx;

	ix = 1;
	set_count_bucket(data);
	while (ix < data->parsed_data->map_height - 1)
	{
		jx = 1;
		while (jx < data->parsed_data->map_width - 1)
		{
			count_space_type(map[ix][jx], data);
			if (map[ix][jx] != 0 && map[ix][jx] != 2) 
				checker = check_mappoint(map, ix, jx);
			if (map[ix][jx] == 3)
			{
				data->player->pos.x = (double)jx;
				data->player->pos.y = (double)ix;
			}
			if (checker)
				return (1);
			jx++;
		}
		ix++;
	}
	return (0);
}