/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isable_strtonbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 01:38:57 by jekim             #+#    #+#             */
/*   Updated: 2021/10/26 00:36:27 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** if the str is able to convert nbr type (int, long, long long us int...)
** this function will returns 0, if not, 1.
*/
int	ft_isable_strtonbr(char *nbr)
{
	int	ret;

	ret = 0;
	while (*nbr && ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		if (!ft_isdigit(*nbr) && !ft_isspace(*nbr))
			return (++ret);
		nbr++;
	}
	return (ret);
}
