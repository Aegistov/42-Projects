/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_sc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:17:14 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/11 14:17:15 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	// if (mod->arg == 's')
		str.arg.str = va_arg(insertion, char *);
	// else
	// {
	// 	str.arg.mint = va_arg(insertion, long int);
	// 	str.num_str = ft_itoa_base(str.arg.mint, 10);
	// 	str.arg.str = str.num_str;
	// }
	index = -1;
	if (!str.arg.str)
		str.arg.str = "(null)";
	str.len = ft_pf_str_precision_check(str.arg.str, mod->precision);
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
