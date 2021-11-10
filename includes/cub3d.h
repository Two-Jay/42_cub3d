/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/11/10 12:26:29 by jekim            ###   ########seoul.kr  */
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
	int						map_hight;
	struct s_mapdata_lst	*rawdata;
}	t_static;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*current_path;
	struct s_static map_data;
}	t_data;

int parse_mapfile(char *filepath, t_data *data);

#endif