/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:31:18 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/21 17:43:35 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	coordinate_extraction(char *piece, int x[], int y[], int *connections)
{
	int		counter;
	int		hash;
	int		num;

	hash = 0;
	counter = 0;
	num = 0;
	while (counter < 19)
	{
		if (piece[counter] != '#')
			counter++;
		if (piece[counter] == '#' && hash != 4)
		{
			x[hash] = counter % 5;
			y[hash] = counter / 5;
			num = num + connections_check(piece, counter);
			hash++;
		}
		counter++;
	}
	*connections = num;
}

t_tet	*ft_pushback(t_tet *node, char *buf, size_t buf_size)
{
	t_tet	*new;
	t_tet	*tmp;

	new = ft_lstnew(buf, buf_size);
	if (node)
	{
		tmp = node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		node = new;
	return (node);
}

t_tet	*ft_input(int fd)
{
	t_tet	*pieces;
	char	buf[22];
	size_t	bytes_read;

	pieces = NULL;
	while ((bytes_read = read(fd, buf, 21)))
	{
		buf[bytes_read] = '\0';
		if (broad_check(buf))
			pieces = ft_pushback(pieces, buf, bytes_read + 1);
		else
			return (0);
	}
	if (!(fine_check(pieces)))
		return (0);
	return (pieces);
}
