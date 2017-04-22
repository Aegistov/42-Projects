/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:58:32 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/23 04:58:33 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove(t_map *map, t_tet *piece, const int x, const int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->map[y + piece->y[i]][x + piece->x[i]] != '\n')
			map->map[y + piece->y[i]][x + piece->x[i]] = '.';
		i++;
	}
}

t_map	ft_map(int capacity, int increment)
{
	t_map	*new;
	int		i;
	int		t;

	i = -1;
	new = ft_memalloc(sizeof(t_map));
	new->min_x = 0;
	new->min_y = 0;
	new->max_x = capacity + increment;
	new->max_y = capacity + increment;
	new->map = (char**)ft_memalloc(sizeof(char*) * ((new->max_y + 1)));
	while (++i < (new->max_y))
		new->map[i] = ft_strnew(sizeof(char) * ((new->max_x) + 1));
	i = -1;
	while (++i < (new->max_y))
	{
		t = -1;
		while (++t < (new->max_x))
			new->map[i][t] = '.';
		new->map[i][t] = '\n';
		new->map[i][t + 1] = '\0';
	}
	return (*new);
}
