/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:54:43 by jekim             #+#    #+#             */
/*   Updated: 2022/01/23 16:40:54 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_max_width_mapdata(t_data *data)
{
	t_mapdata_lst	*lst;
	int				current_width;
	int				max_width;
	int				ix;

	ix = 0;
	current_width = 0;
	max_width = 0;
	lst = data->parsed_data->rawdata->next;
	while (ix < data->map->h)
	{
		current_width = ft_strlen(lst->row);
		if (max_width < current_width)
			max_width = current_width;
		lst = lst->next;
		ix++;
	}
	return (max_width);
}

static t_mapdata_lst	*append_mapdata_lst(char *line, t_mapdata_lst *lst)
{
	t_mapdata_lst	*temp;

	temp = (t_mapdata_lst *)malloc(sizeof(t_mapdata_lst));
	if (!temp)
		return (NULL);
	temp->row = ft_strdup(line);
	lst->next = temp;
	free(line);
	return (temp);
}

int	parse_mapfile_rawdata(int map_fd, t_data *data)
{
	t_mapdata_lst	*lst;
	t_mapdata_lst	*head;
	int				line_check;
	char			*map_line;

	data->map->h = 0;
	lst = (t_mapdata_lst *)malloc(sizeof(t_mapdata_lst));
	head = lst;
	if (skip_line(map_fd, &map_line, &line_check))
		return (1);
	while (line_check > 0)
	{
		lst = append_mapdata_lst(map_line, lst);
		if (!lst)
			return (1);
		data->map->h++;
		line_check = ft_strgnl(map_fd, &map_line);
	}
	lst = append_mapdata_lst(map_line, lst);
	if (!lst)
		return (1);
	data->map->h++;
	data->parsed_data->rawdata = head;
	data->map->w = get_max_width_mapdata(data);
	return (0);
}
