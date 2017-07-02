/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_dioux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:25:14 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/11 14:25:15 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_di(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	// printf("land here\n");
	ft_pf_str_init(&nbr);
	if (mod->arg == 'D')
		mod->length = l;
	nbr.arg.mint = ft_pf_cast(mod, insertion);
	count = 0;
	// printf("[ft_printf_di] nbr: %jd\n", nbr.arg.mint);
	if (nbr.arg.mint < 0)
		nbr.neg = 1;
	nbr.num_str = ft_pf_d_toa_dispatch(mod, nbr.arg.mint, 10);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	return (ft_pf_return(mod, &nbr, count));
}

int		ft_printf_u(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	if (mod->arg == 'U')
		mod->length = l;
	// printf("[ft_printf_u] nbr: %lu\n", (unsigned long)nbr.arg.mint);
	count = 0;
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 10);
	// printf("[ft_printf_u] str: %s\n", nbr.num_str);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	return (ft_pf_return(mod, &nbr, count));
}

int		ft_printf_o(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	count = 0;
	if (mod->hash == 1)
		mod->hash = o;
	if (mod->arg == 'O')
		mod->length = ll;
	// if (nbr.arg.mint == 0)
	// {
	// 	ft_putchar_fd('0', 1);
	// 	return (1);
	// }
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 8);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	return (ft_pf_return(mod, &nbr, count));
}

int		ft_printf_xX(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		count;

	// printf("xX active\n");
	ft_pf_str_init(&nbr);
	nbr.arg.mint = ft_pf_ucast(mod, insertion);
	count = 0;
	if (mod->hash == 1)
		mod->hash = x;
	if (nbr.arg.mint == 0 && !mod->p_active)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	// printf("[ft_printf_x] nbr.arg.mint: %lu\n", nbr.arg.mint);
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 16);
	// printf("[ft_printf_x] num_str: %s\n", nbr.num_str);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	// printf("1\n");
	ft_pf_num_width_pad(mod, &nbr);
	// printf("2\n");
	count = ft_pf_num_print_order(mod, &nbr);
	// printf("3\n");
	return (ft_pf_return(mod, &nbr, count));
}

