/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_RGB.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@42seoul.student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:38:25 by jekim             #+#    #+#             */
/*   Updated: 2021/11/21 01:49:05 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int convet_RGBvalue_to_int(int t, int *parsed)
{
	return (t << 24 | parsed[0] << 16 | parsed[1] << 8 | parsed[2]);
}

static char	**get_RGBstr(int fd, char *key)
{
	char	*line;
	char	**splited;
	char	**rgb_arr;
	int		line_check;

	if (skip_line(fd, &line, &line_check))
		return (NULL);
	splited = get_and_check_splited(line, ' ', 2, key);
	if (splited == NULL)
		return (NULL);
	rgb_arr = ft_split(splited[1], ',');
	if (rgb_arr == NULL
		|| get_splited_len(rgb_arr) != 3)
		return (NULL);
	return (rgb_arr);
}

static int	get_RGBvalue(char **parsed, t_data *data, char key)
{
	int	ix;
	int	ovf_flag;
	int	value;

	ix = 0;
	ovf_flag = 0;
	while (ix != 3 && parsed[ix])
	{
		if (ft_isable_strtonbr(parsed[ix]))
			return (1);
		value = ft_atoi_covf(parsed[ix], &ovf_flag);
		if (ovf_flag == 1 || value < 0 || value > 255)
			return (1);
		if (key == 'F')
			data->parsed_data->F_RGB[ix] = value;
		if (key == 'C')
			data->parsed_data->C_RGB[ix] = value;
		ix++;
	}
	return (0);
}

int	parse_all_RGBvalue(int map_fd, t_data *data)
{
	char	**rgb_parsed;

	data->parsed_data->F_RGB = (int *)malloc(sizeof(int) * 4);
	data->parsed_data->C_RGB = (int *)malloc(sizeof(int) * 4);
	if (!data->parsed_data->F_RGB || !data->parsed_data->C_RGB)
		return (1);
	data->parsed_data->F_RGB[3] = '\0';
	data->parsed_data->C_RGB[3] = '\0';
	rgb_parsed = get_RGBstr(map_fd, "F");
	if (rgb_parsed == NULL
		|| get_RGBvalue(rgb_parsed, data, 'F'))
		return (1);
	data->parsed_data->F_RGB_value
		= convet_RGBvalue_to_int(0, data->parsed_data->F_RGB);
	free_splited(rgb_parsed);
	rgb_parsed = get_RGBstr(map_fd, "C");
	if (rgb_parsed == NULL
		|| get_RGBvalue(rgb_parsed, data, 'C'))
		return (1);
	data->parsed_data->C_RGB_value
		= convet_RGBvalue_to_int(0, data->parsed_data->C_RGB);
	free_splited(rgb_parsed);
	return (0);
}
