/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:38:55 by jekim             #+#    #+#             */
/*   Updated: 2022/03/09 17:20:14 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_line(int fd, char **map_line, int *line_checker)
{
	int	cnt;

	cnt = 0;
	*line_checker = ft_strgnl(fd, map_line);
	while ((int)ft_strlen(*map_line) == 0)
	{
		cnt++;
		if (cnt == 512)
			return (1);
		*line_checker = ft_strgnl(fd, map_line);
	}
	return (0);
}

void	free_splited(char **splited)
{
	int	ix;

	ix = -1;
	if (splited)
	{
		while (splited[++ix])
			free(splited[ix]);
		free(splited);
		splited = NULL;
	}
}

int	get_splited_len(char **splited)
{
	int	ix;

	ix = -1;
	while (splited[++ix])
		;
	return (ix);
}

char	**get_and_check_splited(char *src, char c, int check_l, char *key)
{
	char	**ret;

	ret = ft_split(src, c);
	if (ret == NULL
		|| get_splited_len(ret) != check_l
		|| !ft_strequel(ret[0], key))
	{
		free_splited(ret);
		return (NULL);
	}
	return (ret);
}
