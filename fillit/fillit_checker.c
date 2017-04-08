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

//*************************** 6 FUNCTIONS CURRENTLY REDUCE TO 5 AT LEAST********

int		ft_connections(char *s, int i)
{
	int		c;

	c = 0;
	if (s[i] == '#')
	{
		if (s[i + 1] == '#')
			c++;
		if (i >= 1)
		{
			if (s[i - 1] == '#')
			c++;
		}
		if (s[i + 5] == '#')
			c++;
		if (i >= 5)
		{
			if (s[i - 5] == '#')
			c++;
		}
	}
	return (c);
}

void	ft_coordinate(char *s, int x[], int y[], int *con)
{
	int		i;
	int		n;
	int		num;

	n = 0;
	i = 0;
	num = 0;
	while (i < 19)
	{
		if (s[i] != '#')
			i++;
		if (s[i] == '#' && n != 4)
		{
			x[n] = i % 5;
			y[n] = i / 5;
			num = num + ft_connections(s, i);
			n++;
		}
			i++;
	}
	*con = num;
}

int		broad_check(char *buf)
{
	int		hash;
	int		dot;
	int		i;
	int		newline;

	i = -1;
	newline = 4;
	if (buf)
	{
		hash = ft_mode(buf, '#');
		dot = ft_mode(buf, '.');
		while (++i < 4)
		{
			if (buf[newline] == '\n')
				newline += 5;
		}
		if (hash == 4 && dot == 12 && newline == 24 &&
			(buf[20] == '\n' || buf [20] == '\0'))
			return (1);
		else
			return (0);
	}
	else
		ft_error();
	return (0);
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
//Main input function
int		fine_check(t_tet *pieces)
{
	int		con;

	con = 0;
	if (!pieces)
		return (0);
	while(pieces)
	{
		ft_coordinate(pieces->content, pieces->x, pieces->y, &con);
		if (con != 6 && con != 8)
			return (0);
		if (pieces->next == NULL)
		{
			if (pieces->content[20] != '\0')
				return (0);
		}
		pieces = pieces->next;
	}
	return (1);
}

t_tet	*ft_input(int fd)
{
	t_tet	*cur_block;
	char	buf[22];
	size_t	i;

	cur_block = NULL;
	while ((i = read(fd, buf, 21)))
	{
		buf[i] = '\0';
		if (broad_check(buf))
			cur_block = ft_pushback(cur_block, buf, i + 1);
		else
			return (0);
	}
	if (!(fine_check(cur_block)))
		return (0);
	return (cur_block);
}
