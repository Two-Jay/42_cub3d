/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 16:49:45 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_data *data)
{
	if (put_image_to_window(data)
		|| render_background(data->window, data->parsed_data)
		|| render_wall(data->window, data->camera, data->map))
		return (ERROR_OCCURED);
	return (0);
}
