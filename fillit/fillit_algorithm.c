/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:45:59 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/28 11:46:34 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_coords(t_map *map, t_tet *piece, const int x, const int y)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		if (piece->x[n] + x >= map->max_x || piece->y[n] + y >= map->max_y)
			return (0);
		if (map->map[y + piece->y[n]][x + piece->x[n]] != '.')
			return (0);
		n++;
	}
	ft_convert(map, piece, x, y);
	return (1);
}

void	ft_convert(t_map *map, t_tet *piece, const int x, const int y)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (map->map[y + piece->y[i]][x + piece->x[i]] != '\n')
			map->map[y + piece->y[i]][x + piece->x[i]] = piece->content[0];
	}
}

int		placement(t_map *map, t_tet *piece)
{
	int		x;
	int		y;
	int		piece_x;
	int		piece_y;

	y = -1;
	if (!piece)
		return (1);
	piece_x = ft_minmax(piece->x, 1);
	piece_y = ft_minmax(piece->y, 1);
	while (++y < map->max_y - piece_y)
	{
		x = -1;
		while (++x < map->max_x - piece_x)
		{
			if (compare_coords(map, piece, x, y))
			{
				if (placement(map, piece->next))
					return (1);
				else
					ft_remove(map, piece, x, y);
			}
		}
	}
	return (0);
}
