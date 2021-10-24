/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:33 by jekim             #+#    #+#             */
/*   Updated: 2021/10/24 14:19:52 by jekim            ###   ########seoul.kr  */
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

typedef struct s_static
{
	char	*NO_image_filename;
	int		NO_image_fd;
	char	*SO_image_filename;
	int		SO_image_fd;
	char	*WE_image_filename;
	int		WE_image_fd;
	char	*EA_image_filename;
	int		EA_image_fd;
	int		floor_R;
	int		floor_G;
	int		floor_B;
	int		celling_R;
	int		celling_G;
	int		celling_B;
}	t_static;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_static file_data;
}	t_data;

#endif