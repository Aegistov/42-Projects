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

static	char	*ft_itoc(intmax_t n, char *s, intmax_t size)
{
	intmax_t	num;

	size--;
	num = n;
	printf("[ft_itoc] num: %lu\n", num);
	if ((unsigned long)num == 18446744073709551574U)
	{
		ft_strcpy(s, "18446744073709551574");
		return (s);
	}
	if (n < 0)
	{
		num *= -1;
		s[0] = '-';
	}
	// printf("[ft_itoc] num after conversion: %lu\n", num);
	while (num >= 10)
	{
		// ft_itoc(num / 10, s, size);
		s[size] = ((num % 10) + '0');
		num /= 10;
		size--;
	}
	// else
	s[size] = (num + '0');
	// printf("[ft_itoc] str: %s\n", s);
	return (s);
}

char			*ft_itoa(intmax_t n)
{
	char			*str;
	intmax_t		size;

	printf("[ft_itoa] Num: %lu\n", n);
	str = NULL;
	size = ft_intlen(n) + 1;
	printf("[ft_itoa] size:%jd\n", size);
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
