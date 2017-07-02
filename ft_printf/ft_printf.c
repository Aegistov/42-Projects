/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:36:42 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 11:36:43 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_printf(const char *restrict format, ...)
{
	va_list		arguments;
	int			index;
	int			len;
	// char		*str;
	// char		*tmp;

	// str = (char *)malloc(2);
	len = 0;
	index = 0;
	va_start(arguments, format);
	// printf("Reading initiated...\n");
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (format[index + 1] != '\0')
			{
				// printf("Activated\n");
				// index++;
				// len += ft_strlen(format);
				// index++;
				len += ft_printf_parse(format, arguments, &index);
				index++;
			}
			else
				return (0);
			// printf("len after parse: %d\n", len);
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			// printf("Char: %c\tLen: %d\n", format[index], len);
			len++;
			// tmp = ft_strchjoin(str, format[index]);
			// free (str);
			// str = tmp;
			// printf("str: %s\n", str);
			index++;
		}
	}
	// printf("Reading complete.\n");
	// ft_putchar_fd(*format, 1);
	return (len);
}
