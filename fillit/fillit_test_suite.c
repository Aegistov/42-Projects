/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_test_suite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:15:43 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/18 14:20:11 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	map_display(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i] != '\0')
	{
		ft_putstr(map->map[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_tet		*tetriminos;
	t_tet		*tmp;
	t_map		*field;
	int			increment;
	int			fd;

	if (argc != 2)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (!(tetriminos = ft_input(fd)))
		ft_error();
	tmp = tetriminos;
	ft_hash(tmp);
	increment = 0;
	field = ft_memalloc(sizeof(t_map));
	*field = ft_map(tetrimino_num(tmp), increment);
	while (!placement(field, tetriminos))
	{
		increment++;
		*field = ft_map(tetrimino_num(tetriminos), increment);
	}
	map_display(field);
	return (0);
}
