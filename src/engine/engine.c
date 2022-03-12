/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:08:04 by jekim             #+#    #+#             */
/*   Updated: 2022/03/12 21:38:57 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_data *data)
{
	if (put_image_to_window(data)
		|| render_background(data->window, data->parsed_data)
		|| render_wall(data))
		return (ERROR_OCCURED);
	return (0);
}
