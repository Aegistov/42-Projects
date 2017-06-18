/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:43:38 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/11 12:43:40 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_pf_return(t_mods *mod, t_pf_string *arg, int count)
{
	if ((mod->precision > mod->width))
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", arg->len, mod->precision, count, mod->width);
		return (arg->len + mod->width + count);
	}
	else if (mod->p_active && (arg->len == 1 && arg->num_str[0] == '0'))
	{
		// printf("Case 3\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", arg->len, mod->precision, count, mod->width);
		return (mod->width + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", arg->len, mod->precision, count, mod->width);
		return (arg->len + mod->width + count);	
	}
}
