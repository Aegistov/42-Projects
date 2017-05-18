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

	len = 0;
	index = 0;
	va_start(arguments, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			// len += index - 1;
			len += ft_printf_parse(format, arguments, &index);
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			index++;
		}
	}
	// ft_putchar_fd(*format, 1);
	return (index + len);
}
