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

char	*ft_pf_d_toa_dispatch(t_mods *mod, uintmax_t nbr)
{
	char	*str;

	str = NULL;
	if (mod->length == ll || mod->length == z)
		str = ft_pf_lldtoa(nbr);
	else if (mod->length == hh)
		str = ft_pf_hhdtoa(nbr);
	else
		str = ft_itoa(nbr);
	return (str);
}

char	*ft_pf_ud_toa_dispatch(t_mods *mod, uintmax_t nbr)
{
	char	*str;

	str = NULL;
	if (mod->length == ll || mod->length == z)
		str = ft_pf_lldtoa(nbr);
	else if (mod->length == hh)
		str = ft_pf_hhdtoa(nbr);
	else
		str = ft_itoa(nbr);
	return (str);
}