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
	// printf("Parse Initiated\n");
	if (!(mod = (t_mods *)ft_memalloc(sizeof(t_mods))))
		return (-1);
	if (format[(*start)] == '%')
	{
		// printf("(*start) prepre: %d\n", (*start));
		(*start)++;
		// printf("(*start) pre: %d\nformat[index] : %c\n", (*start), format[(*start)]);
		(*start) += ft_printf_capture_flags(format, mod, *start);
		// printf("(*start) post flags: %d\n", (*start));
		(*start) += ft_printf_capture_width(format, mod, (*start));
		// printf("Width captured: %d\n(*start) post width: %d\n", mod->width, (*start));
		if (format[(*start)] == '.')
		{
			// printf("(*start) pre: %d\n", (*start));
			mod->p_active = 1;
			// if (mod->p_active)
			// 	printf("Precision activated\n");
			(*start) += ft_printf_capture_precision(format, mod, (*start));
			// printf("(*start) post: %d\n", (*start));
		}
		(*start) += ft_printf_capture_length(format, mod, (*start));
		// printf("Precision captured: %d\n(*start) post precision: %d\n", mod->precision, (*start));
	}
	// printf("Difference: %d\n", (*start) - *start + 1);
	// printf("parse format[index]%c\n", format[(*start)]);
	// (*start)++;
	// printf("Launching flag dispatch\n");
	return (ft_printf_flag_dispatch(mod, arguments, format[(*start)]));
}
