/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_dispatch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:27:37 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 14:27:38 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void		pf_string_init(t_pf_string *str)
{
	str->pad = NULL;
	str->len = 0;
	str->neg = 0;
	str->wflag = 0;
	str->num_str = NULL;
}

intmax_t	ft_printf_cast(t_mods *mod, va_list insertion)
{
	intmax_t	holder;
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
		holder = (char)holder;
	else if (mod->length == 1)
		holder = (short int)holder;
	else if (mod->length == 3)
		holder = (long int)holder;
	else if (mod->length == 4)
		holder = (long long int)holder;
	else if (mod->length == 6)
		holder = (size_t)holder;
	else if (mod->length == 7)
		holder = (intmax_t)holder;
	else
		holder = (int)holder;
	return (holder);
}

int		integer_signage(t_mods *mod, int sign, char *pad, int holder)
{
	int		count;

	count = 0;
	if (mod->plus && sign == 0)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (sign == 1 && holder != -2147483648)
	{
		if (pad && pad[0] != ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
		else if (!pad)
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	}
	else if (mod->space && sign == 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int		precision_check(char *str, int precision)
{
	int		len;

	len = 0;
	if (precision > 0)
	{
		while (len < precision)
		{
			if (str[len] == '\0')
				break ;
			len++;
		}
	}
	else
		len = ft_strlen(str);
	// printf("Len in precision_check: %d\n", len);
	return (len);
}

void	padding_for_num(t_mods *mod, t_pf_string *nbr)
{
	int		flag_sign;
	int 	width;

	width = mod->width > mod->precision ? mod->width : mod->precision;
	flag_sign = 0;
	if ((mod->space || mod->plus) && !nbr->neg)
		flag_sign = 1;
	if (width - nbr->len - flag_sign > 0)
	{
		width -= (nbr->len + flag_sign + nbr->neg);
		if (mod->zero || (mod->precision > mod->width))
			nbr->pad = ft_strfill(nbr->pad, '0', width);
		else
			nbr->pad = ft_strfill(nbr->pad, ' ', width);
		if (mod->width > mod->precision)
			mod->width -= (nbr->len + flag_sign + nbr->neg);
		else
			mod->precision -= (nbr->len + flag_sign + nbr->neg);
	}
}

char	*padding(t_mods *mod, int len, int sign)
{
	char	*pad;
	int		flag_sign;
	int 	width;

	width = mod->width;
	flag_sign = 0;
	pad = NULL;
	if ((mod->space || mod->plus) && sign == 0)
		flag_sign = 1;
	if (width - len - flag_sign > 0)
	{
		// printf("Width: %d\tLen: %d\tflag_sign: %d\n", *width, len, flag_sign);
		mod->width -= (len + flag_sign + sign);
		if (mod->zero)
			pad = ft_strfill(pad, '0', mod->width);
		else
			pad = ft_strfill(pad, ' ', mod->width);
		// *width -= len - flag_sign;
		// printf("Width in padding: %d\nPadding: %s\n", *width, pad);
	}
	return (pad);
}

int		ft_printf_di(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		index;
	int		count;

	pf_string_init(&nbr);
	index = -1;
	nbr.arg.mint = ft_printf_cast(mod, insertion);
	count = 0;
	if (nbr.arg.mint < 0)
	{
		nbr.neg = 1;
		if (nbr.arg.mint != -2147483648)
			nbr.arg.mint *= -1;
	}
	nbr.num_str = ft_itoa(nbr.arg.mint);
	nbr.len = precision_check(nbr.num_str, mod->precision);
	padding_for_num(mod, &nbr);
	count = integer_signage(mod, nbr.neg, nbr.pad, nbr.arg.mint);
	if (!mod->left_align && nbr.pad)
		ft_putstr_fd(nbr.pad, 1);
	if (nbr.neg == 1 && nbr.pad && nbr.pad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (nbr.num_str[++index] != '\0' && index < nbr.len)
		ft_putchar_fd(nbr.num_str[index], 1);
	if(mod->left_align && nbr.pad)
	{
		if (mod->zero)
		{
			free(nbr.pad);
			ft_strfill(nbr.pad, ' ', mod->width);
		}
		ft_putstr_fd(nbr.pad, 1);
	}
	if (mod->precision > mod->width)
	{
		// printf("Len: %d\tPrecision: %d\tCount: %d\n", nbr.len, mod->precision, count);
		return (nbr.len + mod->precision + count);
	}
	else
		return (nbr.len + mod->width + count);	
}

// void	ft_printf_o(va_list insertion)
// {
// 	printf("Here's a o!\n");
// }
// void	ft_printf_x(va_list insertion)
// {
// 	printf("Here's a x!\n");
// }
// void	ft_printf_u(va_list insertion)
// {
// 	printf("Here's a u!\n");
// }

int		ft_printf_c(va_list insertion, t_mods *mod)
{
	t_pf_string	chr;
	int		index;
	int		width;

	width = mod->width;
	pf_string_init(&chr);
	chr.arg.ch = va_arg(insertion, int);
	chr.len = 1;
	index = -1;
	if (!chr.arg.ch)
		chr.arg.ch = 0;
	if (width - chr.len > 0)
	{
		mod->width -= chr.len;
		chr.pad = ft_strfill(chr.pad, ' ', mod->width);
	}
	if (!mod->left_align && chr.pad)
		ft_putstr_fd(chr.pad, 1);
	ft_putchar_fd(chr.arg.ch, 1);
	if(mod->left_align && chr.pad)
		ft_putstr_fd(chr.pad, 1);
	return (chr.len + mod->width);
}

int		ft_printf_s(va_list insertion, t_mods *mod)
{
	t_pf_string	str;
	int			index;
	int			width;

	width = mod->width;
	pf_string_init(&str);
	str.arg.str = va_arg(insertion, char *);
	index = -1;
	if (!str.arg.str)
		str.arg.str = "(null)";
	str.len = precision_check(str.arg.str, mod->precision);
	if (width - str.len > 0)
	{
		mod->width -= str.len;
		str.pad = ft_strfill(str.pad, ' ', mod->width);
	}
	if (!mod->left_align && str.pad != NULL)
		ft_putstr_fd(str.pad, 1);
	while (str.arg.str[++index] != '\0' && index < str.len)
		ft_putchar_fd(str.arg.str[index], 1);
	if(mod->left_align && str.pad)
		ft_putstr_fd(str.pad, 1);
	return (str.len + mod->width);
}


// void	ft_printf_f(va_list insertion)
// {
// 	printf("Here's a f!\n");
// }

// void	ft_printf_e(va_list insertion)
// {
// 	printf("Here's a e!\n");
// }

// void	ft_printf_g(va_list insertion)
// {
// 	printf("Here's a g!\n");
// }

// void	ft_printf_p(va_list insertion)
// {
// 	printf("Here's a p!\n");
// }

int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument)
{
	int (*argument_list[127])(va_list, t_mods *);
	int	len;
	argument_list['d'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	// argument_list['h'] = ft_printf_hhd;
	// argument_list['o'] = ft_printf_o;
	// argument_list['x'] = ft_printf_x;
	// argument_list['u'] = ft_printf_di;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['%'] = ft_printf_p;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	// printf("dispatcher initiated\n");
	len = (*argument_list[argument])(insertion, mod);
	// char (*flag_functions[5])(const char *restrict)
	// flag_functions[0] = char (*flag_minus)(const char *restrict);
	// flag_functions[1] = char (*flag_plus)(const char *restrict);
	// flag_functions[2] = char (*flag_zero)(const char *restrict);
	// flag_functions[3] = char (*flag_space)(const char *restrict);
	// flag_functions[4] = char (*flag_hash)(const char *restrict);
	// flag_functions[5] = '\0';
	// printf("Len in dispatch: %d\n", len);
	return (len);
}
