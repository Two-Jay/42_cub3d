/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:23:08 by jekim             #+#    #+#             */
/*   Updated: 2021/12/26 16:20:06 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_mapdata_lst
{
	char *row;
	struct s_mapdata_lst	*next;
}	t_mapdata_lst;

typedef struct s_player
{
	double pos_x;
	double pos_y;
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
	int						F_RGB_value;
	int						*C_RGB;
	int						C_RGB_value;
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

typedef struct s_img
{
	void	*main_image_ptr;
	int		*main_image_data;
	int		size_length;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	char			*current_path;
	int				**map_matrix;
	struct s_player *player;
	struct s_window	*window;
	struct s_static *parsed_data;
	struct s_img	*img;
}	t_data;

typedef struct s_vec
{
	double x;
	double y;
}	t_vec;

#endif