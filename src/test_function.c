/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:47:50 by jekim             #+#    #+#             */
/*   Updated: 2021/11/11 07:47:58 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_mapmatrix(char **map)
{
	int ix;
	
	ix = -1;
	while (map[++ix])
		printf("%s   [%zu]\n", map[ix], ft_strlen(map[ix]));
}