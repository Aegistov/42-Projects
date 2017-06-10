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

// static	char	*ft_itoc_up(intmax_t n, char *s, intmax_t size, int base)
// {
// 	intmax_t	num;
// 	static char		*hex = "0123456789ABCDEF";

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
// 	while (num >= base || num < -base)
// 	{
// 		// ft_itoc(num / base, s, size);
// 		// printf("[ft_itoc] char: %lld\n", ((num % base) * -1));
// 		s[size] = hex[(num % base) * (n < 0 ? -1 : 1)];
// 		// s[size] = ((num % base) * (n < 0 ? -1 : 1) + '0');
// 		num /= base;
// 		size--;
// 	}
// 	s[size] = hex[(num % base) * (n < 0 ? -1 : 1)];;
// 	// printf("[ft_itoc] str: %ss\n", s);
// 	return (s);
// }

// char			*ft_itoa_base_up(intmax_t n, int base)
// {
// 	char			*str;
// 	intmax_t		size;

// 	// printf("[ft_itoa] Num: %zu\n", n);
// 	str = NULL;
// 	size = ft_intlen_base(n, base) + 1;
// 	// printf("[ft_itoa] size:%jd\n", size);
// 	if (n == 0)
// 	{
// 		str = ft_strnew(1);
// 		str[0] = '0';
// 	}
// 	// else if ((unsigned long)n == 18446744073709551574U)
// 	// {
// 	// 	str = ft_strdup("18446744073709551574");
// 	// 	return (str);
// 	// }
// 	else
// 	{
// 		if (!(str = (char*)malloc(sizeof(char) * size)))
// 			return (NULL);
// 		str = ft_itoc_up(n, str, size - 1, base);
// 	}
// 	str[size - 1] = '\0';
// 	// printf("str: %s\n", str);
// 	return (str);
// }


// static	char	*ft_itoc(intmax_t n, char *s, intmax_t size, int base)
// {
// 	intmax_t	num;
// 	static char		*hex = "0123456789abcdef";

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
// 	while (num >= base || num < -base)
// 	{
// 		// ft_itoc(num / base, s, size);
// 		// printf("[ft_itoc] char: %lld\n", ((num % base) * -1));
// 		s[size] = hex[(num % base) * (n < 0 ? -1 : 1)];
// 		// s[size] = ((num % base) * (n < 0 ? -1 : 1) + '0');
// 		num /= base;
// 		size--;
// 	}
// 	s[size] = hex[(num % base) * (n < 0 ? -1 : 1)];
// 	// printf("[ft_itoc] str: %ss\n", s);
// 	return (s);
// }

char			*ft_itoa_base(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_intlen_base(n, base);
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
		while (n >= base || n < -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	return (str);
}

char			*ft_itoa_base_up(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";

	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_intlen_base(n, base);
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
		while (n >= base || n < -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	return (str);
}

