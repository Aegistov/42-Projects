/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:53:21 by mmorel            #+#    #+#             */
/*   Updated: 2017/04/20 11:53:23 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 32
# define MAX_FD   4096
# define MALVER(x) if (!x) return (-1);

int get_next_line(const int fd, char **line);
#endif
