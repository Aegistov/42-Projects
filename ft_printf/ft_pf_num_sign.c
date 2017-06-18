/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 19:57:25 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 19:57:29 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pf_num_sign(t_mods *mod, int sign, char *pad)
{
	int		count;

	count = 0;
	if (mod->plus && sign == 0 && (mod->arg == 'd' || mod ->arg == 'i'))
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (sign == 1)
	{
		if (pad && pad[0] != ' ')
		{
			ft_putchar_fd('-', 1);
			// count++;
		}
		else if (!pad)
		{
			ft_putchar_fd('-', 1);
			// count++;
		}
	}
	else if (mod->space && sign == 0 && (mod->arg == 'd' || mod ->arg == 'i'))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}
