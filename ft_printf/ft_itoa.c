/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:53:33 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/08 16:12:44 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*ft_itoc(int n, char *s, unsigned int size)
{
	unsigned int	num;

	size--;
	num = n;
	if (n < 0)
	{
		num = -n;
		s[0] = '-';
	}
	if (num >= 10)
	{
		ft_itoc(num / 10, s, size);
		s[size] = ((num % 10) + '0');
	}
	else
		s[size] = (num + '0');
	return (s);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;

	str = NULL;
	size = ft_intlen(n) + 1;
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str = ft_itoc(n, str, size - 1);
	}
	str[size - 1] = '\0';
	return (str);
}
