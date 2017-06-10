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

// char	*ft_pf_lldtoc(long long int n, char *s, intmax_t size)
// {
// 	long long int	num;

// 	size--;
// 	num = n;
// 	// printf("[ft_itoc] nbr: %lld\n", n);
// 	if (n < 0)
// 	{
// 		// printf("converting\n");
// 		// num *= -1;
// 		s[0] = '-';
// 	}
// 	// printf("[ft_itoc] nbr after conv: %lld\n", num);
// 	while (num >= 10 || num < -10)
// 	{
// 		// ft_itoc(num / 10, s, size);
// 		// printf("[ft_itoc] char: %lld\n", ((num % 10) * -1));
// 		s[size] = ((num % 10) * (n < 0 ? -1 : 1) + '0');
// 		num /= 10;
// 		size--;
// 	}
// 	s[size] = (num * (n < 0 ? -1 : 1) + '0');
// 	// printf("[ft_itoc] str: %ss\n", s);
// 	return (s);
// }

char			*ft_pf_lldtoa_base(intmax_t n, int base)
{
	// char		*str;
	// long long	nbr;
	// int			len;

	// nbr = n;
	// printf("[ft_pf_lldtoa] nbr: %lld\n", nbr);
	// if (n == 0)
	// 	return ("0");
	// if (n < 0)
	// 	nbr *= -1;
	// printf("[ft_pf_lldtoa] nbr after conv: %lld\n", nbr);
	// len = ft_pf_lld_len_base(nbr, 10) + 1;
	// if (n < 0)
	// 	len++;
	// str = (char *)malloc(len);
	// str[len--] = '\0';
	// while (nbr)
	// {
	// 	str[len--] = (nbr % 10) + '0';
	// 	nbr /= 10;
	// }
	// if (n < 0)
	// 	str[0] = '-';
	// return (str);

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

// char			*ft_pf_lldtoa_base_up(intmax_t n, int base)
// {
// 	char			*str;
// 	intmax_t		size;
// 	static char		*hex = "0123456789ABCDEF";

// 	// printf("[ft_itoa] Num: %jd\n", n);
// 	str = NULL;
// 	size = ft_pf_lld_len_base(n, 10);
// 	// printf("[ft_itoa] size:%jd\n", size);
// 	if (n == 0)
// 		return ("0");
// 	// else if ((unsigned long)n == 18446744073709551574U)
// 	// {
// 	// 	str = ft_strdup("18446744073709551574");
// 	// 	return (str);
// 	// }
// 	else
// 	{
// 		if (!(str = (char*)malloc(sizeof(char) * size)))
// 			return (NULL);
// 		if (n < 0)
// 			str[0] = '-';
// 		str[size--] = '\0';
// 		// size--;
// 		while (n >= base || n < -base)
// 		{
// 			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
// 			n /= base;
// 			size--;
// 		}
// 		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
// 	}
// 	// str[size - 1] = '\0';
// 	// printf("str: %s\n", str);
// 	return (str);
// }

// char	*ft_pf_hhdtoc(char n, char *s, intmax_t size)
// {
// 	char	num;

// 	size--;
// 	num = n;
// 	// printf("[ft_itoc] nbr: %lld\n", n);
// 	if (n < 0)
// 	{
// 		// printf("converting\n");
// 		// num *= -1;
// 		s[0] = '-';
// 	}
// 	// printf("[ft_itoc] nbr after conv: %lld\n", num);
// 	while (num >= 10 || num < -10)
// 	{
// 		// ft_itoc(num / 10, s, size);
// 		// printf("[ft_itoc] char: %lld\n", ((num % 10) * -1));
// 		s[size] = ((num % 10) * (n < 0 ? -1 : 1) + '0');
// 		num /= 10;
// 		size--;
// 	}
// 	s[size] = (num * (n < 0 ? -1 : 1) + '0');
// 	// printf("[ft_itoc] str: %ss\n", s);
// 	return (s);
// }

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

// char			*ft_pf_hhdtoa_base_up(char n, int base)
// {
// 	char			*str;
// 	intmax_t		size;
// 	static char		*hex = "0123456789ABCDEF";

// 	// printf("[ft_itoa] Num: %zu\n", n);
// 	str = NULL;
// 	size = ft_pf_hhd_len_base(n, 10);
// 	// printf("[ft_itoa] size:%jd\n", size);
// 	if (n == 0)
// 		return ("0");
// 	// else if ((unsigned long)n == 18446744073709551574U)
// 	// {
// 	// 	str = ft_strdup("18446744073709551574");
// 	// 	return (str);
// 	// }
// 	else
// 	{
// 		if (!(str = (char*)malloc(sizeof(char) * size)))
// 			return (NULL);
// 		if (n < 0)
// 			str[0] = '-';
// 		str[size--] = '\0';
// 		// size--;
// 		while (n >= base || n < -base)
// 		{
// 			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
// 			n /= base;
// 			size--;
// 		}
// 		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
// 	}
// 	// str[size - 1] = '\0';
// 	// printf("str: %s\n", str);
// 	return (str);
// }
