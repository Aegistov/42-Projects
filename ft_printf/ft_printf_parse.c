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
	int		index;
	t_mods	*mod;

	index = *start;
	if (!(mod = (t_mods *)ft_memalloc(sizeof(t_mods))))
		return (-1);
	if (format[index] == '%')
	{
		index++;
		// printf("Index pre: %d\n", index);
		index += ft_printf_capture_flags(format, mod, index);
		// printf("Flags captured: %s\nIndex post flags: %d\n", flags, index);
		index += ft_printf_capture_width(format, mod, index);
		// printf("Width captured: %d\nIndex post width: %d\n", width, index);
		if (format[index] == '.')
		{
			// printf("Index pre: %d\n", index);
			mod->p_active = 1;
			index += ft_printf_capture_precision(format, mod, index);
			// printf("Index post: %d\n", index);
		}
		index += ft_printf_capture_length(format, mod, index);
		// printf("Precision captured: %d\nIndex post precision: %d\n", mod->precision, index);
	}
	// printf("Difference: %d\n", index - *start + 1);
	*start = index + 1;
	return (ft_printf_flag_dispatch(mod, arguments, format[index]));
}
