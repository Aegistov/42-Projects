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

#include "libftprintf.h"

int		ft_printf_parse(const char *restrict format, va_list arguments, int *start)
{
	char	flags[6];
	char	length[3];
	int		index;
	int		width;
	int		precision;

	index = *start;
	width = 0;
	precision = 0;
	if (format[index] == '%')
	{
		index++;
		// printf("Index pre: %d\n", index);
		index += ft_printf_capture_flags(format, flags, index);
		// printf("Flags captured: %s\nIndex post flags: %d\n", flags, index);
		index += ft_printf_capture_width(format, &width, index);
		// printf("Width captured: %d\nIndex post width: %d\n", width, index);
		if (format[index] == '.')
			index += ft_printf_capture_precision(format, &precision, index);
		index += ft_printf_capture_length(format, length, index);
		// printf("Precision captured: %d\nIndex post precision: %d\n", precision, index);
	}
	// printf("Difference: %d\n", index - *start + 1);
	*start = index + 1;
	return (ft_printf_flag_dispatch(flags, width, precision, arguments, format[index]));
}
