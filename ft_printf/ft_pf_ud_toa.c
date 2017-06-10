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

// char	*ft_pf_llutoc(unsigned long long n, char *s, intmax_t size)
// {
// 	unsigned long long	num;

// 	size--;
// 	num = n;
// 	while (num >= 10)
// 	{
// 		// ft_itoc(num / 10, s, size);
// 		s[size] = ((num % 10) + '0');
// 		num /= 10;
// 		size--;
// 	}
// 	s[size] = (num + '0');
// 	// printf("[ft_itoc] str: %s\n", s);
// 	return (s);
// }

char			*ft_pf_llutoa_base(uintmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";
	// printf("LOWER ACTIVE\n");
	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_pf_llu_len_base(n, base);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		// size--;
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

char			*ft_pf_llutoa_base_up(uintmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";
	// printf("UP ACTIVE\n");
	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_pf_llu_len_base(n, base);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		// size--;
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

// char	*ft_pf_hhutoc(unsigned char n, char *s, intmax_t size)
// {
// 	unsigned char	num;

// 	size--;
// 	num = n;
// 	while (num >= 10)
// 	{
// 		// ft_itoc(num / 10, s, size);
// 		s[size] = ((num % 10) + '0');
// 		num /= 10;
// 		size--;
// 	}
// 	s[size] = (num + '0');
// 	// printf("[ft_itoc] str: %s\n", s);
// 	return (s);
// }

char			*ft_pf_hhutoa_base(unsigned char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	// printf("[ft_itoa] Num: %hhx\n", (unsigned char)n);
	str = NULL;
	size = ft_pf_hhu_len_base(n, base);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			// printf("str[size]: %c\n", str[size]);
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}

char			*ft_pf_hhutoa_base_up(unsigned char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";

	// printf("[ft_itoa] Num: %zu\n", n);
	str = NULL;
	size = ft_pf_hhu_len_base(n, base);
	// printf("[ft_itoa] size:%jd\n", size);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	// str[size - 1] = '\0';
	// printf("str: %s\n", str);
	return (str);
}
