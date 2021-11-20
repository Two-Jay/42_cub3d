/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@42seoul.student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:47:50 by jekim             #+#    #+#             */
/*   Updated: 2021/11/21 00:34:23 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_mapmatrix(int **map, t_data *data)
{
	int ix;
	int jx;
	
	ix = 0;
	while (ix < data->parsed_data->map_height)
	{
		jx = 0;
		while (jx < data->parsed_data->map_width)
		{
			printf("%d", map[ix][jx]);
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
