/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/11/14 00:55:18 by jekim            ###   ########seoul.kr  */
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

# define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
# define trc(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%c\n", x); }
# define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
# define trp(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%p\n", x); }

# define MAPTILE_CHARSET "0NSEW"

# define BUTTON_REDCROSS 0x6d357408
# define KEY_ESC 0x35
# define KEY_W 0xd
# define KEY_S 0x1
# define KEY_A 0x0
# define KEY_D 0x2

typedef struct s_mapdata_lst
{
	char *row;
	struct s_mapdata_lst	*next;
}	t_mapdata_lst;

typedef struct s_player
{
	int pos_x;
	int pos_y;
	int	health;
	int	speed;
	int armo;
}	t_player;

typedef struct s_static
{
	char					*NO_img_filepath;
	char					*SO_img_filepath;
	char					*WE_img_filepath;
	char					*EA_img_filepath;
	int						*F_RGB;
	int						*C_RGB;
	int						map_width;
	int						map_height;
	int						space_cnt;
	int						N_cnt;
	int						S_cnt;
	int						E_cnt;
	int						W_cnt;
	struct s_mapdata_lst	*rawdata;
}	t_static;

typedef struct	s_window
{
	int 			resol_max_x;
	int 			resol_max_y;
	int				resol_basic_x;
	int				resol_basic_y;
	void			*win_ptr;
}	t_window;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*main_image_ptr;
	char			*current_path;
	int				**map_matrix;
	struct s_window	window;
	struct s_static parsed_data;
}	t_data;

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
int	draw(void);

/*
**	test_function
*/
void print_mapmatrix(int **map, t_data *data);

#endif