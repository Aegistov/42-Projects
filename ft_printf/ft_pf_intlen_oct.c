/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_intlen_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 21:11:40 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 21:11:43 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pf_intlen_oct(uintmax_t n)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n /= 8;
		count++;
	}
	return (count);
}
