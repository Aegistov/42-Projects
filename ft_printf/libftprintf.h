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

typedef	struct s_mods
{
	unsigned int	left_align : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	zero : 1;
	unsigned int	hash : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
					none,
					h,
					hh,
					l,
					ll,
					L,
					z,
					j,
					t
	}				length;
}				t_mods;

typedef struct 	s_pf_string
{
	char			*pad;
	int				len;
	unsigned int	neg : 1;
	unsigned int	wflag : 1;
	char			*num_str;
	union			arg
	{
		int				sint;
		unsigned int 	uint;
		double			dbl;
		char			*str;
		char			ch;
		void			*vdpt;
		intmax_t		mint;
	}				arg;
}				t_pf_string;

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
int		ft_intlen(intmax_t n);
char	*ft_itoa(intmax_t n);
char	*ft_strnew(size_t size);
int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument);
int		ft_printf_capture_flags(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_precision(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_width(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_length(const char *restrict format, t_mods *mod, int index);

#endif
