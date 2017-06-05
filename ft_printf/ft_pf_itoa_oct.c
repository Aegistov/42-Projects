/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa_oct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 21:10:36 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 21:10:38 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoc_oct(uintmax_t n, char *str, unsigned int size)
{
	uintmax_t	num;

	size--;
	num = n;
	while (num >= 8)
	{
		str[size] = ((num % 8) + '0');
		num /= 8;
		size--;
	}
	str[size] = ((num % 8) + '0');
	return(str);
}

char	*ft_pf_itoa_oct(uintmax_t n)
{
	char			*str;
	unsigned int	size;

	str = NULL;
	size = ft_pf_intlen_oct(n) + 1;
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
	{
		if (!(str = (char *)malloc(size)))
			return (NULL);
		str = ft_itoc_oct(n, str, size - 1);
	}
	str[size - 1] = '\0';
	return (str);
}
