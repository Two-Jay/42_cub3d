/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/10/30 16:37:45 by jekim            ###   ########.fr       */
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

typedef enum s_maptile_type
{
	NON = 0,
	WALL,
	PLYR,
	FLR,
	SPRT
}	t_maptile_type;

typedef struct s_static
{
	char	*NO_image_filename;
	char	*SO_image_filename;
	char	*WE_image_filename;
	char	*EA_image_filename;
	int		*F_RGB;
	int		*C_RGB;
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