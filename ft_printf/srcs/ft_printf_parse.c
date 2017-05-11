/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:37:47 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/10 15:37:50 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_printf_parse(const char *restrict format)
{
	char	flags[6];
	int		count;

	count = 0;
	while (*format != '%')
	{
		ft_putchar_fd(*format, 1);
		format++;
	}
	if (*format == '%')
	{
		format++;
		while (*format == '-' || *format == '0' || *format == '+' || *format == '#' || *format == ' ')
		{
			flags[count] = *format;
			flags[count + 1] = '\0';
			printf("Format: %c\nFlags: %s\n", *format, flags);
			format++;
			count++;
		}
		if (ft_strlen(flags))
			ft_printf_flag_dispatch(format, flags);
	}
}
