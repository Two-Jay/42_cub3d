/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/11/10 17:04:38 by jekim            ###   ########seoul.kr  */
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
# include "../lib/minilibx_opengl/mlx.h"

# define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
# define trc(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%c\n", x); }
# define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
# define trp(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%p\n", x); }

# define SPACE_CHARSET "0NSEW"

typedef struct s_mapdata_lst
{
	char *row;
	struct s_mapdata_lst	*next;
}	t_mapdata_lst;

typedef struct s_static
{
	char					*NO_image_filename;
	char					*SO_image_filename;
	char					*WE_image_filename;
	char					*EA_image_filename;
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

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*current_path;
	char			**map_matrix;
	struct s_static parsed_data;
}	t_data;

int parse_mapfile(char *filepath, t_data *data);

#endif