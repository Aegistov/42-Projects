/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_d_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:28:36 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 22:28:37 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_pf_lldtoa_base(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	// printf("[ft_itoa] Num: %jd\n", n);
	str = NULL;
	size = ft_pf_lld_len_base(n, 10);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	// else if ((unsigned long)n == 18446744073709551574U)
	// {
	// 	str = ft_strdup("18446744073709551574");
	// 	return (str);
	// }
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[size--] = '\0';
		// size--;
		while (n >= base || n < -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

char			*ft_pf_hhdtoa_base(char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	// printf("[ft_itoa] Num: %hhd\n", n);
	str = NULL;
	size = ft_pf_hhd_len_base(n, 10);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[size--] = '\0';
		// size--;
		while (n >= base || n <= -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			// printf("str[size]: %c\tn: %hhd\n", str[size], n);
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}
