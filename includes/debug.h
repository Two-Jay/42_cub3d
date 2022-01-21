/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:28:17 by jekim             #+#    #+#             */
/*   Updated: 2022/01/17 02:30:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define trs(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%s\n", x); }
# define trc(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%c\n", x); }
# define tri(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%d\n", x); }
# define trd(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%lf\n", x); }
# define trp(x...) { printf("[%s:%d] %s = ", __func__, __LINE__, #x); printf("%p\n", x); }

int print_mapmatrix(int **map, t_data *data);
int check_struct_p(t_data *data);

#endif