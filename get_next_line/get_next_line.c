/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:53:11 by mmorel            #+#    #+#             */
/*   Updated: 2017/04/20 12:16:03 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		load_single_line(char **line, char *src, char c)
{
	int		breakpoint;

	breakpoint = -1;
	while (src[++breakpoint])
	{
		if (src[breakpoint] == c)
			break ;
	}
	if (!(*line = ft_strnew(breakpoint)))
		return (0);
	ft_memcpy(*line, src, breakpoint);
	return (breakpoint);
}

char	*load_database_file(char *file, char *buffer, int selector)
{
	char	*tmp;
	int		breakpoint;

	if (selector == 1)
	{
		if (!file)
			if (!(file = (char*)ft_memalloc((BUF_SIZE + 1))))
				return (NULL);
		tmp = ft_strjoin(file, buffer);
		free(file);
		file = tmp;
	}
	else
	{
		breakpoint = -1;
		while (file[++breakpoint])
		{
			if (file[breakpoint] == '\n')
				break ;
		}
		tmp = ft_strsub(file, breakpoint + 1, ft_strlen(file) - breakpoint);
		free(file);
		file = tmp;
	}
	return (file);
}

int		get_next_line(const int fd, char **line)
{
	int					bytes_read;
	char				buf[BUF_SIZE + 1];
	static char			**database;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!database)
		MALVER((database = (char**)ft_memalloc(sizeof(char *) * (MAX_FD + 1))));
	while ((bytes_read = read(fd, buf, BUF_SIZE)))
	{
		buf[bytes_read] = '\0';
		database[fd] = load_database_file(database[fd], buf, 1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes_read < BUF_SIZE && !ft_strlen(database[fd]))
		return (0);
	if (load_single_line(line, database[fd], '\n') < ft_strlen(database[fd]))
		database[fd] = load_database_file(database[fd], buf, 0);
	else
		ft_strclr(database[fd]);
	return (1);
}
