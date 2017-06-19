/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 21:34:51 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/18 21:34:53 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_C(va_list insertion, t_mods *mod)
{
	t_pf_string	chr;
	int		width;

	width = mod->width;
	ft_pf_str_init(&chr);
	chr.arg.wc = va_arg(insertion, wchar_t);
	chr.len = ft_pf_putwchar(chr.arg.wc);
	if (width - chr.len > 0)
	{
		mod->width -= chr.len;
		chr.wpad = ft_strfill(chr.wpad, ' ', mod->width);
	}
	if (!mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	// ft_putchar_fd(chr.arg.ch, 1);
	if(mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	return (chr.len + mod->width);
}

int 	ft_printf_S(va_list insertion, t_mods *mod)
{
	t_pf_string	str;
	int			width;

	width = mod->width;
	ft_pf_str_init(&str);
	// printf("Initialized\n");
	str.arg.wstr = va_arg(insertion, wchar_t *);
	// printf("Loaded\n");
	str.len = ft_pf_wstr_len(str.arg.wstr);
	// str.len = ft_pf_str_precision_check(str.arg.str, mod->precision);
	if (width - str.len > 0)
	{
		mod->width -= str.len;
		str.wpad = ft_strfill(str.wpad, ' ', mod->width);
	}
	if (!mod->left_align && str.wpad != NULL)
		ft_putstr_fd(str.wpad, 1);
	ft_pf_putwstr(str.arg.wstr);
	if(mod->left_align && str.wpad)
		ft_putstr_fd(str.wpad, 1);
	return (str.len + mod->width);
}