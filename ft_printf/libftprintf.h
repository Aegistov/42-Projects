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
	unsigned int	p_active : 1;
	unsigned int	width;
	unsigned int	precision;
	int 			arg;
	enum			{
					empty,
					o,
					x
	}				hash;
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
	char			*ppad;
	char			*wpad;
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
int		ft_intlen_base(intmax_t n, int base);
char	*ft_itoa_base_up(intmax_t n, int base);
int 	ft_intlen_hex(uintmax_t n);
int		ft_pf_intlen_oct(uintmax_t n);
char	*ft_itoa(intmax_t n);
char	*ft_itoa_base(intmax_t n, int base);
char	*ft_itoa_hex(uintmax_t n, int arg);
char	*ft_pf_itoa_oct(uintmax_t n);
char	*ft_strnew(size_t size);
char	*ft_strdup(char *s1);
int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument);
int		ft_printf_capture_flags(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_precision(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_width(const char *restrict format, t_mods *mod, int index);
int		ft_printf_capture_length(const char *restrict format, t_mods *mod, int index);
int		ft_pf_num_print_order(t_mods *mod, t_pf_string *nbr);
int		ft_pf_num_sign(t_mods *mod, int sign, char *pad);

int		ft_pf_llu_len_base(unsigned long long n, const int base);
int		ft_pf_hhu_len_base(unsigned char n, const int base);

int		ft_pf_lld_len_base(long long int n, const int base);
int		ft_pf_hhd_len_base(char n, const int base);

char			*ft_pf_llutoa_base(uintmax_t n, int base);
char			*ft_pf_llutoa_base_up(uintmax_t n, int base);
char			*ft_pf_hhutoa_base(unsigned char n, int base);
char			*ft_pf_hhutoa_base_up(unsigned char n, int base);

char			*ft_pf_lldtoa_base(intmax_t n, int base);
char			*ft_pf_hhdtoa_base(char n, int base);


char	*ft_pf_d_toa_dispatch(t_mods *mod, intmax_t nbr, int base);
char	*ft_pf_ud_toa_dispatch(t_mods *mod, uintmax_t nbr, int base);

int		ft_printf_p(va_list insertion, t_mods *mod);
int		ft_printf_pct(va_list insertion, t_mods *mod);
int		ft_printf_di(va_list insertion, t_mods *mod);
int		ft_printf_u(va_list insertion, t_mods *mod);
int		ft_printf_o(va_list insertion, t_mods *mod);
int		ft_printf_xX(va_list insertion, t_mods *mod);
int		ft_printf_s(va_list insertion, t_mods *mod);
int		ft_printf_c(va_list insertion, t_mods *mod);

void		ft_pf_str_init(t_pf_string *str);
int		ft_pf_str_precision_check(char *str, int precision);
char	*ft_pf_str_width_pad(t_mods *mod, int len, int sign);
intmax_t	ft_pf_ucast(t_mods *mod, va_list insertion);
intmax_t	ft_pf_cast(t_mods *mod, va_list insertion);
void	ft_pf_num_width_pad(t_mods *mod, t_pf_string *nbr);
void	ft_pf_num_precision_pad(t_mods *mod, t_pf_string *nbr);
int		ft_pf_num_precision_check(t_mods *mod, t_pf_string *nbr);

int ft_pf_return(t_mods *mod, t_pf_string *arg, int count);

#endif
