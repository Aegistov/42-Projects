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

int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument)
{
	static char *arg = "diuoxcspDXUSCOP%";
	int (*argument_list[127])(va_list, t_mods *);
	int	len;
	len = 0;
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
	argument_list['C'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	argument_list['S'] = ft_printf_s;
	argument_list['O'] = ft_printf_o;	
	argument_list['p'] = ft_printf_p;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	argument_list['%'] = ft_printf_pct;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	// printf("dispatcher initiated\n");
	if (ft_strchr(arg, argument))
		len = (*argument_list[argument])(insertion, mod);
	else
		len = write(1, &argument, 1);
	// printf("Len in dispatch: %d\n", len);
	return (len);
}
