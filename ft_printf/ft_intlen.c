/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:02:51 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/08 16:08:58 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_intlen_base(intmax_t n, int base)
{
	intmax_t		i;

	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i);
	}
	else
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i + 1);
	}
}


int		ft_intlen(intmax_t n)
{
	intmax_t		i;

	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
	else
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
		return (i + 1);
	}
}
