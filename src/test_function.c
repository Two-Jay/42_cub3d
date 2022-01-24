/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:47:50 by jekim             #+#    #+#             */
/*   Updated: 2022/01/23 16:43:08 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_mapmatrix(t_map *map)
{
	int ix;
	int jx;
	
	ix = 0;
	while (ix < map->h)
	{
		jx = 0;
		while (jx < map->w)
		{
			printf("%d", map->mtrx[ix][jx]);
			jx++;
		}
		printf("\n");
		ix++;
	}
	return (0);
}

int check_struct_p(t_data *data)
{
	trp(data);
	trp(data->parsed_data);
	trp(data->window);
	trp(data->player);
	return (0);
}
