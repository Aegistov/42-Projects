/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:21:01 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:21:02 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	ft_pf_ucast(t_mods *mod, va_list insertion)
{
	intmax_t	holder;
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
	{
		// printf("hh\n");
		holder = (unsigned char)holder;
	}
	else if (mod->length == 1)
		holder = (unsigned short int)holder;
	else if (mod->length == 3 || mod->arg == 'O' || mod->arg == 'U')
	{
		// printf("l\n");
		holder = (unsigned long int)holder;
	}
	else if (mod->length == 4)
		holder = (unsigned long long int)holder;
	else if (mod->length == 6)
		holder = (size_t)holder;
	else if (mod->length == 7)
		holder = (intmax_t)holder;
	else
		holder = (unsigned int)holder;
	return (holder);
}

intmax_t	ft_pf_cast(t_mods *mod, va_list insertion)
{
	intmax_t	holder;
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
	{
		// printf("hh\n");
		holder = (char)holder;
	}
	else if (mod->length == 1)
		holder = (short int)holder;
	else if (mod->length == 3 || mod->arg == 'D')
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
