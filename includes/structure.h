/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:23:08 by jekim             #+#    #+#             */
/*   Updated: 2022/01/23 16:39:10 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_intvec
{
	int		x;
	int		y;
}	t_intvec;

typedef struct s_pixel
{
	double			distance;
	unsigned int	*color;
}	t_pixel;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	deltaDist;
	t_vec	sideDist;
	double	distance;
}	t_ray;

typedef struct s_mapdata_lst
{
	char *row;
	struct s_mapdata_lst	*next;
}	t_mapdata_lst;

typedef struct s_player
{
	t_vec pos;
	t_vec dir;
	t_vec plain;
	double camera_x;
	double time;
	double old_time;
}	t_player;

typedef struct s_static
{
	char					*NO_img_filepath;
	char					*SO_img_filepath;
	char					*WE_img_filepath;
	char					*EA_img_filepath;
	int						*F_RGB;
	unsigned int			F_RGB_value;
	int						*C_RGB;
	unsigned int			C_RGB_value;

	int						space_cnt;
	int						N_cnt;
	int						S_cnt;
	int						E_cnt;
	int						W_cnt;
	struct s_mapdata_lst	*rawdata;
}	t_static;

typedef struct s_img
{
	void			*img_ptr;
	unsigned int	*data_addr;
	int				size_length;
	int				bpp;
	int				endian;
}	t_img;

typedef struct	s_window
{
	int 			max_w;
	int 			max_h;
	int				w;
	int				h;
	void			*win_ptr;
	void			*mlx_ptr;
	t_pixel			**pixel;
	t_ray			*ray;
	double			sin_unit;
	double			cos_unit;
	double			distance;
	struct s_img	*img;
}	t_window;

typedef struct s_map
{
	int				w;
	int				h;
	int				**mtrx;
}	t_map;

typedef struct s_data
{
	char			*current_path;
	struct s_map	*map;
	struct s_player *player;
	struct s_window	*window;
	struct s_static *parsed_data;
}	t_data;



#endif