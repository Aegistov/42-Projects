/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:14:34 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:14:35 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_p(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.vdpt = va_arg(insertion, void *);
	// printf("Address: %p\n", nbr.arg.vdpt);
	mod->hash = 2;
	count = 0;
	// printf("[ft_printf_x] nbr.arg.mint: %lu\n", nbr.arg.mint);
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 16);
	// printf("[ft_printf_x] num_str: %s\n", nbr.num_str);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	// printf("mod->width is: %d\n", mod->width);
	// if (mod->width < 0)
	// 	mod->width = 0;
	count = ft_pf_num_print_order(mod, &nbr);
	return(ft_pf_return(mod, &nbr, count));
	// if (mod->precision > mod->width)
	// {
	// 	// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
	// 	return (nbr.len + count);
	// }
	// else
	// {
	// 	// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
	// 	return (nbr.len + mod->width + count);	
	// }
}
