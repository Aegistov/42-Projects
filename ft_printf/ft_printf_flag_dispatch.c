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

int		ft_printf_o(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	// printf("Casting...\n");
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	// printf("Casted\n");
	count = 0;
	if (nbr.arg.mint == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 8);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_xX(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	count = 0;
	if (nbr.arg.mint == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	// printf("[ft_printf_x] nbr.arg.mint: %lu\n", nbr.arg.mint);
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 16);
	// printf("[ft_printf_x] num_str: %s\n", nbr.num_str);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_u(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	// printf("[ft_printf_u] nbr: %llu\n", (unsigned long long)nbr.arg.mint);
	count = 0;
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 10);
	// printf("[ft_printf_u] str: %s\n", nbr.num_str);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else if (mod->p_active && (nbr.len == 1 && nbr.num_str[0] == '0'))
		return (mod->width + count);
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_di(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_cast(mod, insertion);
	count = 0;
	// printf("[ft_printf_di] nbr: %jd\n", nbr.arg.mint);
	if (nbr.arg.mint < 0)
		nbr.neg = 1;
	nbr.num_str = ft_pf_d_toa_dispatch(mod, nbr.arg.mint, 10);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	if ((mod->precision > mod->width))
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);
	}
	else if (mod->p_active && (nbr.len == 1 && nbr.num_str[0] == '0'))
		return (mod->width + count);
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_c(va_list insertion, t_mods *mod)
{
	t_pf_string	chr;
	int		index;
	int		width;

	width = mod->width;
	ft_pf_str_init(&chr);
	chr.arg.ch = va_arg(insertion, int);
	chr.len = 1;
	index = -1;
	if (!chr.arg.ch)
		chr.arg.ch = 0;
	if (width - chr.len > 0)
	{
		mod->width -= chr.len;
		chr.wpad = ft_strfill(chr.wpad, ' ', mod->width);
	}
	if (!mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	ft_putchar_fd(chr.arg.ch, 1);
	if(mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	return (chr.len + mod->width);
}

int		ft_printf_s(va_list insertion, t_mods *mod)
{
	t_pf_string	str;
	int			index;
	int			width;

	width = mod->width;
	ft_pf_str_init(&str);
	if (mod->arg == 's')
		str.arg.str = va_arg(insertion, char *);
	else
	{
		str.arg.mint = va_arg(insertion, long int);
		str.num_str = ft_itoa_base(str.arg.mint, 10);
		str.arg.str = str.num_str;
	}
	index = -1;
	if (!str.arg.str)
		str.arg.str = "(null)";
	str.len = precision_check(str.arg.str, mod->precision);
	if (width - str.len > 0)
	{
		mod->width -= str.len;
		str.wpad = ft_strfill(str.wpad, ' ', mod->width);
	}
	if (!mod->left_align && str.wpad != NULL)
		ft_putstr_fd(str.wpad, 1);
	while (str.arg.str[++index] != '\0' && index < str.len)
		ft_putchar_fd(str.arg.str[index], 1);
	if(mod->left_align && str.wpad)
		ft_putstr_fd(str.wpad, 1);
	return (str.len + mod->width);
}

int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument)
{
	int (*argument_list[127])(va_list, t_mods *);
	int	len;
	mod->arg = argument;
	argument_list['d'] = ft_printf_di;
	argument_list['D'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	argument_list['o'] = ft_printf_o;
	argument_list['x'] = ft_printf_xX;
	argument_list['X'] = ft_printf_xX;
	argument_list['u'] = ft_printf_u;
	argument_list['U'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	argument_list['S'] = ft_printf_s;
	argument_list['O'] = ft_printf_o;	
	argument_list['p'] = ft_printf_p;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['%'] = ft_printf_p;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	// printf("dispatcher initiated\n");
	len = (*argument_list[argument])(insertion, mod);
	// printf("Len in dispatch: %d\n", len);
	return (len);
}
