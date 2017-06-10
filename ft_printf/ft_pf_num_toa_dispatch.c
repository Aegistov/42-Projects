/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_toa_dispatch.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:40:20 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 21:40:22 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_d_toa_dispatch(t_mods *mod, intmax_t nbr, int base)
{
	char	*str;

	str = NULL;
	if (mod->length == ll || mod->length == z || mod->length == j)
		str = ft_pf_lldtoa_base(nbr, base);
	else if (mod->length == hh)
		str = ft_pf_hhdtoa_base(nbr, base);
	else
		str = ft_itoa_base(nbr, base);
	return (str);
}

char	*ft_pf_ud_toa_dispatch(t_mods *mod, uintmax_t nbr, int base)
{
	char	*str;

	str = NULL;
	if (mod->length == ll || mod->length == z || mod->length == j)
		str = (mod->arg == 'X') ? ft_pf_llutoa_base_up(nbr, base) :
			ft_pf_llutoa_base(nbr, base);
	else if (mod->length == hh)
	{
		// printf("TRIGERRED\n");
		str = (mod->arg == 'X') ? ft_pf_hhutoa_base_up(nbr, base) :
			ft_pf_hhutoa_base(nbr, base);
	}
	else
		str = (mod->arg == 'X') ? ft_itoa_base_up(nbr, base) :
			ft_itoa_base(nbr, base);
	return (str);
}