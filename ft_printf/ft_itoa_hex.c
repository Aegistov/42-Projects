/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:15:04 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 14:15:07 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_itoc_hex(uintmax_t n, char *str, unsigned int size, int arg)
{
	uintmax_t	num;

	size--;
	num = n;
	while (num >= 16)
	{
		if (num % 16 < 10)
			str[size] = ((num % 16) + '0');
		else
		{
			if (arg == 'X')
				str[size] = ((num % 16) - 10 + 'A');
			else
				str[size] = ((num % 16) - 10 + 'a');
		}
		num /= 16;
		size--;
	}
	if (num % 16 < 10)
		str[size] = ((num % 16) + '0');
	else
	{
		if (arg == 'X')
			str[size] = ((num % 16) - 10 + 'A');
		else
			str[size] = ((num % 16) - 10 + 'a');
	}
	return (str);
}

char		*ft_itoa_hex(uintmax_t n, int arg)
{
	char			*str;
	unsigned int	size;

	str = NULL;
	size = ft_intlen_hex(n) + 1;
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
	{
		if (!(str = (char *)malloc(size)))
			return (NULL);
		str = ft_itoc_hex(n, str, size - 1, arg);
	}
	str[size - 1] = '\0';
	return (str);
}
