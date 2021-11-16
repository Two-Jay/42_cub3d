/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:56:03 by jekim             #+#    #+#             */
/*   Updated: 2021/11/16 19:18:09 by jekim            ###   ########.fr       */
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

int validate_mapdata_object(t_data *data)
{
	if (data->parsed_data.N_cnt != 1
		|| data->parsed_data.space_cnt == 0)
		return (1);
	return (0);
}