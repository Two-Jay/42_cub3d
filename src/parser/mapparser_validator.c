/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:56:03 by jekim             #+#    #+#             */
/*   Updated: 2022/03/13 15:41:04 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	validate_mapdata_border(int **map, t_data *data)
{
	int	ix;
	int	height;
	int	width;

	ix = 0;
	height = data->map->h;
	width = data->map->w;
	while (ix < width)
	{
		if (map[0][ix] == MAPTILE_INNERSPACE
			|| map[height - 1][ix] == MAPTILE_INNERSPACE)
			return (ERROR_OCCURED);
		ix++;
	}
	ix = 0;
	while (ix < height)
	{
		if (map[ix][0] == MAPTILE_INNERSPACE
			|| map[ix][width - 1] == MAPTILE_INNERSPACE)
			return (ERROR_OCCURED);
		ix++;
	}
	return (0);
}

int	validate_mapdata_object(t_data *data)
{
	printf("check");
	if (data->parsed_data->spwanpoint_cnt != 1
		|| data->parsed_data->space_cnt == 0)
		return (ERROR_OCCURED);
	return (0);
}
