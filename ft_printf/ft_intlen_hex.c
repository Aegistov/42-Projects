/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:08:58 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 15:09:02 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_intlen_hex(uintmax_t n)
{
	unsigned int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
