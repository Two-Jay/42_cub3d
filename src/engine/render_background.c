/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:28:10 by jekim             #+#    #+#             */
/*   Updated: 2022/01/30 20:29:15 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int render_background(t_window *win, t_static *parsed)
{
	int x;
	int y;
	t_pixel **pxlptr;
	
	pxlptr = win->pixel;
	y = -1;
	while (++y <= win->h / 2)
	{
		x = -1;
		while (++x < win->w)
			*(pxlptr[x][y].color) = parsed->F_RGB_value;
	}
	while (++y < win->h)
	{
		x = -1;
		while (++x < win->w)
			*(pxlptr[x][y].color) = parsed->C_RGB_value;
	}
	return (0);
}
