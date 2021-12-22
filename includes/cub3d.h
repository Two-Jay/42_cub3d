/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/12/20 17:24:52 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx_mms_20210621/mlx.h"
# include "./structure.h"

# define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
# define trc(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%c\n", x); }
# define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
# define trp(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%p\n", x); }

/*
** key binding
*/
# define BUTTON_REDCROSS 0x6d357408
# define KEY_ESC 0x35
# define KEY_W 0xd
# define KEY_S 0x1
# define KEY_A 0x0
# define KEY_D 0x2

/*
**	initiation_part
*/
int init_game(int argc, char **argv, char **env, t_data **data);

/*
**	parser_part
*/
int parse_mapfile(char *filepath, char** env, t_data *data);
int	parse_all_RGBvalue(int map_fd, t_data *data);
int	parse_all_imagepaths(int map_fd, t_data *data);
int	parse_mapfile_rawdata(int map_fd, t_data *data);
int convert_mapdata_matrix(t_data *data);
int validate_mapdata_space(int **map, t_data *data);
int validate_mapdata_object(t_data *data);
int validate_mapdata_border(int **map, t_data *data);

int skip_line(int fd, char **map_line, int *line_checker);
void free_splited(char **splited);
int	get_splited_len(char **splited);
char **get_and_check_splited(char *src, char c, int check_l, char *key);

/*
**	hooks_part
*/
void set_hooks(t_data *data);

/*
**	engine_part
*/
int	render(t_data *data);

/*
**	test_function
*/
int check_struct_p(t_data *data);
int print_mapmatrix(int **map, t_data *data);

#endif