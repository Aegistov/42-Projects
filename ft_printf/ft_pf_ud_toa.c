/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ud_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:59:10 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 21:59:11 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_ulltoc(unsigned long long n, char *s, intmax_t size)
{
	unsigned long long	num;

	size--;
	num = n;
	while (num >= 10)
	{
		// ft_itoc(num / 10, s, size);
		s[size] = ((num % 10) + '0');
		num /= 10;
		size--;
	}
	s[size] = (num + '0');
	// printf("[ft_itoc] str: %s\n", s);
	return (s);
}

char			*ft_pf_llutoa(uintmax_t n)
{
	char			*str;
	intmax_t		size;

	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_pf_llu_len_base(n, 10) + 1;
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	// else if ((unsigned long)n == 18446744073709551574U)
	// {
	// 	str = ft_strdup("18446744073709551574");
	// 	return (str);
	// }
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str = ft_pf_ulltoc(n, str, size - 1);
	}
	str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

char	*ft_pf_hhutoc(unsigned char n, char *s, intmax_t size)
{
	unsigned char	num;

	size--;
	num = n;
	while (num >= 10)
	{
		// ft_itoc(num / 10, s, size);
		s[size] = ((num % 10) + '0');
		num /= 10;
		size--;
	}
	s[size] = (num + '0');
	// printf("[ft_itoc] str: %s\n", s);
	return (s);
}

char			*ft_pf_hhutoa(uintmax_t n)
{
	char			*str;
	intmax_t		size;

	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_pf_hhu_len_base(n, 10) + 1;
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	// else if ((unsigned long)n == 18446744073709551574U)
	// {
	// 	str = ft_strdup("18446744073709551574");
	// 	return (str);
	// }
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str = ft_pf_hhutoc(n, str, size - 1);
	}
	str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

