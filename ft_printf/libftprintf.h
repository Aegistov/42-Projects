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
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *restrict format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_printf_parse(const char *restrict format, va_list arguments, int *start);
int		ft_printf_capture_flags(const char *restrict format, char *flags, int index);
int		ft_strlen(char const *str);
void	ft_printf_flag_dispatch(char *flags, int width, int precision, va_list insertion, int argument);
int		ft_printf_capture_width(const char *restrict format, int *width, int index);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
int		ft_printf_capture_precision(const char *restrict format, int *precision, int index);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);

#endif
