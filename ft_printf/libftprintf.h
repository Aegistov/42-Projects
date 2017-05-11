/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:21:23 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 12:21:24 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
#include <stdio.h>

int		ft_printf(const char *restrict format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_printf_parse(const char *restrict format);

#endif
