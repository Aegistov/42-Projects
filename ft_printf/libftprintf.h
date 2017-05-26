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
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *restrict format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_printf_parse(const char *restrict format, va_list arguments, int *start);
int		ft_strlen(char const *str);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char const *str);
int		ft_atoi(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strfill(char *str, char c, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_intlen(int n);
char	*ft_itoa(int n);
char	*ft_strnew(size_t size);
int		ft_printf_flag_dispatch(char *flags, int width, int precision, va_list insertion, int argument);
int		ft_printf_capture_flags(const char *restrict format, char *flags, int index);
int		ft_printf_capture_precision(const char *restrict format, int *precision, int index);
int		ft_printf_capture_width(const char *restrict format, int *width, int index);
int		ft_printf_capture_length(const char *restrict format, char *length, int index);

#endif
