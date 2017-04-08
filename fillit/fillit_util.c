/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:49:27 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/23 04:49:29 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//Error output message
void	ft_error(void)
{
	ft_putstr_fd("error\n", 1);
}
//Helper function for ft_reset, finds coords closest to (0,0)
int		ft_minmax(int s[], int op)
{
	int		holder;
	int		i;

	i = 0;
	holder = s[0];
	if (op == 0)
	{
		while (i < 4)
		{
			if (s[i] < holder)
				holder = s[i];
			i++;
		}
	}
	else if (op == 1)
	{
		while (i < 4)
		{
			if (s[i] > holder)
				holder = s[i];
			i++;
		}
	}
	return (holder);
}
//Resets coords of given tetrimino to as close to (0,0) as possible
void	ft_reset(int x[], int y[])
{
	int		min_x;
	int		min_y;
	int		i;

	i = -1;
	min_x = ft_minmax(x, 0);
	min_y = ft_minmax(y, 0);
	while (++i < 4)
		x[i] -= min_x;
	i = -1;
	while (++i < 4)
		y[i] -= min_y;
}
//Replaces it with a specific letter for each tetrimino
void	ft_hash(t_tet *lst)
{
	char	c;

	c = 65;
	while (lst)
	{
			ft_reset(lst->x, lst->y);
			lst->content = ft_memalloc(2);
			lst->content[0] = c;
			lst->content[1] = '\0';
			c++;
			lst = lst->next;
	}
}
//Formula for determining the smallest size map needed for given tetriminos
int		tetrimino_num(t_tet *piece)
{
	int		i;

	i = 0;
	while (piece)
	{
		i++;
		piece = piece->next;
	}
	// printf("num of pieces: %d\n", i);
	return (ft_sqt((i * 4)));
}
