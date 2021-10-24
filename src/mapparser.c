/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:58:51 by jekim             #+#    #+#             */
/*   Updated: 2021/10/25 03:23:52 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	run_mapfile(char *filepath)
{
	int	path_l;
	int	fd_check;

	path_l = ft_strlen(filepath);
	if (!ft_strequel(filepath + path_l - 4, ".cub"))
		ft_strerr("Error : invaild map file\n");
	fd_check = open(filepath, O_RDONLY, NULL);
	if (fd_check == -1)
		ft_strerr("Error : invaild map file\n");
	return (fd_check);
}

int	parse_mapfile(char *filepath, t_data *data)
{
	int	map_fd;

	trp(data);
	map_fd = run_mapfile(filepath);
	tri(map_fd);
	return (0);
}