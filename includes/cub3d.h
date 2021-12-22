/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/12/22 13:15:38 by jekim            ###   ########.fr       */
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
# include "./debug.h"

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
int		render(t_data *data);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
void	put_line_orthos_x_from_top(t_data *data, int line_len, int x_position, int color);
void	put_line_orthos_x_from_middle(t_data *data, int diameter, int x_position, int color);
void	put_line_orthos_x_from_bottom(t_data *data, int line_len, int x_position, int color);

#endif