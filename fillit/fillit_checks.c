#include "fillit.h"

int		connections_check(char *s, int i)
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

int		broad_check(char *buf)
{
	int		hash;
	int		dot;
	int		counter;
	int		newline;

	counter = -1;
	newline = 4;
	if (buf)
	{
		hash = ft_mode(buf, '#');
		dot = ft_mode(buf, '.');
		while (++counter < 4)
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

int		fine_check(t_tet *pieces)
{
	int		connections;

	connections = 0;
	if (!pieces)
		return (0);
	while(pieces)
	{
		coordinate_extraction(pieces->content, pieces->x, pieces->y, &connections);
		if (connections != 6 && connections != 8)
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
