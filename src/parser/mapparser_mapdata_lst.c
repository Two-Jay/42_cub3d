/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_mapdata_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:54:43 by jekim             #+#    #+#             */
/*   Updated: 2021/11/16 19:12:28 by jekim            ###   ########.fr       */
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
	lst = data->parsed_data.rawdata->next;
	while (ix < data->parsed_data.map_height)
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

	data->parsed_data.map_height = 0;
	lst = (t_mapdata_lst *)malloc(sizeof(t_mapdata_lst));
	head = lst;
	if (skip_line(map_fd, &map_line, &line_check))
		return (1);
	while (line_check > 0)
	{
		lst = append_mapdata_lst(map_line, lst);
		if (!lst)
			return (1);
		data->parsed_data.map_height++;
		line_check = ft_strgnl(map_fd, &map_line);
	}
	lst = append_mapdata_lst(map_line, lst);
	if (!lst)
		return (1);
	data->parsed_data.map_height++;
	data->parsed_data.rawdata = head;
	data->parsed_data.map_width = get_max_width_mapdata(data);
	return (0);
}
