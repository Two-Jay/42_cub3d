/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:57:04 by jekim             #+#    #+#             */
/*   Updated: 2022/03/13 15:48:16 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_mappoint(int **map, int ix, int jx)
{
	if (map[ix - 1][jx - 1] == MAPTILE_OUTSPACE
		|| map[ix - 1][jx] == MAPTILE_OUTSPACE
		|| map[ix - 1][jx + 1] == MAPTILE_OUTSPACE
		|| map[ix][jx - 1] == MAPTILE_OUTSPACE
		|| map[ix][jx + 1] == MAPTILE_OUTSPACE
		|| map[ix + 1][jx - 1] == MAPTILE_OUTSPACE
		|| map[ix + 1][jx] == MAPTILE_OUTSPACE
		|| map[ix + 1][jx + 1] == MAPTILE_OUTSPACE)
		return (ERROR_OCCURED);
	return (0);
}

static void	count_space_type(int point, t_data *data)
{
	if (point == MAPTILE_INNERSPACE)
		data->parsed_data->space_cnt++;
	else if (point == MAPTILE_SPWAN)
		data->parsed_data->spwanpoint_cnt++;
}

static void	set_count_bucket(t_data *data)
{
	data->parsed_data->space_cnt = 0;
	data->parsed_data->spwanpoint_cnt = 0;
}

static void	set_pos(t_data *data, int ix, int jx)
{
	data->camera->pos.x = (double)jx;
	data->camera->pos.y = (double)ix;
}

int	validate_mapdata_space(int **map, t_data *data)
{
	int	checker;
	int	ix;
	int	jx;

	ix = 1;
	checker = 0;
	set_count_bucket(data);
	while (ix < data->map->h - 1)
	{
		jx = 1;
		while (jx < data->map->w - 1)
		{
			count_space_type(map[ix][jx], data);
			if (map[ix][jx] == MAPTILE_INNERSPACE)
				checker = check_mappoint(map, ix, jx);
			if (map[ix][jx] == 3)
				set_pos(data, ix, jx);
			if (checker)
				return (ERROR_OCCURED);
			jx++;
		}
		ix++;
	}
	return (0);
}
