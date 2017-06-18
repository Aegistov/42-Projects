/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:27:33 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:27:34 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pf_num_width_pad(t_mods *mod, t_pf_string *nbr)
{
	int		flag_sign;
	int 	width;
	int		hash;

	hash = mod->hash;
	flag_sign = 0;
	if ((mod->space || mod->plus) && !nbr->neg)
		flag_sign = 1;
	// printf("Width loading...\nWidth: %d\tPrecision: %d\tLen: %d\tFlag Sign: %d\tNeg: %d\tHash: %d\n", mod->width, mod->precision, nbr->len, flag_sign, nbr->neg, hash);
	if (mod->width > (unsigned int)(nbr->len + flag_sign + hash))
	{
		// printf("Width loaded\n");
		// printf("Width loading...\nWidth: %d\tPrecision: %d\tLen: %d\tFlag Sign: %d\tNeg: %d\n", mod->width, mod->precision, nbr->len, flag_sign, nbr->neg);
		width = (nbr->len == 1 && nbr->num_str[0] == '0' && mod->p_active) ? mod->width : mod->width - (nbr->len + flag_sign + hash);
			// width = mod->width - (nbr->len + flag_sign + nbr->neg);
		// printf("Width is: %d\n", width);
		if (mod->zero && !nbr->ppad)
			nbr->wpad = ft_strfill(nbr->wpad, '0', width);
		else
			nbr->wpad = ft_strfill(nbr->wpad, ' ', width);
		// printf("1mod->width is: %d\n", mod->width - (nbr->len + flag_sign) - 2);
		if (!(nbr->len == 1 && nbr->num_str[0] == '0' && mod->p_active))
			mod->width -= (nbr->len + flag_sign + hash);
		 // printf("mod->width is: %d\n", mod->width - (nbr->len + flag_sign) - 2);
		// printf("wpad: %s\n", nbr->wpad);
	}
	else
		mod->width = 0;
	// printf("Width too small\n");
}

void	ft_pf_num_precision_pad(t_mods *mod, t_pf_string *nbr)
{
	mod->precision -= ft_strlen(nbr->num_str);
	if (nbr->neg)
		mod->precision += 1;
	nbr->ppad = ft_strfill(nbr->ppad, '0', mod->precision);
	// printf("[num_precision_pad] ppad: %s\n", nbr->ppad);
}

int		ft_pf_num_precision_check(t_mods *mod, t_pf_string *nbr)
{
	int		len;

	len = 0;
	if ((int)mod->precision <= ft_strlen(nbr->num_str))
		len = ft_strlen(nbr->num_str);
	else
	{
		len = (nbr->neg) ? mod->precision + 1 : mod->precision;
		ft_pf_num_precision_pad(mod, nbr);
	}
	// printf("[num_precision_check] Len: %d\n", len);
	return (len);
}
