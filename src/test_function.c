/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:47:50 by jekim             #+#    #+#             */
/*   Updated: 2021/11/16 19:04:48 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int print_mapmatrix(int **map, t_data *data)
{
	int ix;
	int jx;
	
	ix = 0;
	while (ix < data->parsed_data.map_height)
	{
		jx = 0;
		while (jx < data->parsed_data.map_width)
		{
			printf("%d", map[ix][jx]);
			jx++;
		}
		printf("\n");
		ix++;
	}
	return (0);
}