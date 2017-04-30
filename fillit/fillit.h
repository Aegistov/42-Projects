/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:46:01 by mmorel            #+#    #+#             */
/*   Updated: 2017/04/22 01:00:29 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct			s_map
{
	int					min_x;
	int					min_y;
	int					max_x;
	int					max_y;
	char				**map;
}						t_map;

int						broad_check(char *buf);
int						fine_check(t_tet *pieces);
int						connections_check(char *s, int i);
void					coordinate_extraction(char *piece, int x[], int y[],
		int *connections);
void					ft_error(void);
void					reset(t_tet *piece);
void					hash(char *content);
int						placement(t_map *map, t_tet *piece);
t_map					ft_map(int capacity, int increment);
void					ft_remove(t_map *map, t_tet *piece, const int x,
		const int y);
void					ft_convert(t_map *map, t_tet *piece, const int x,
		const int y);
int						ft_algorithm(t_map *map, t_tet *piece);
void					ft_hash(t_tet *lst);
int						ft_gatekeeper(t_map *map, t_tet *piece);
int						tetrimino_num(t_tet *piece);
int						ft_sqt(int num);
void					clear_map(t_map *map);

#endif
