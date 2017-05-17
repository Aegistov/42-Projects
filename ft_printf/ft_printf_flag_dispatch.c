/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_dispatch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:27:37 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 14:27:38 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_di(va_list insertion)
{
	// printf("Here's a di!\n");
	ft_putnbr_fd(va_arg(insertion, int), 1);
}

// void	ft_printf_o(va_list insertion)
// {
// 	printf("Here's a o!\n");
// }
// void	ft_printf_x(va_list insertion)
// {
// 	printf("Here's a x!\n");
// }
// void	ft_printf_u(va_list insertion)
// {
// 	printf("Here's a u!\n");
// }

void	ft_printf_c(va_list insertion)
{
	// printf("Here's a c!\n");
	ft_putchar_fd(va_arg(insertion, int), 1);
}

void	ft_printf_s(va_list insertion)
{
	// printf("Here's a s!\n");
	ft_putstr_fd(va_arg(insertion, char *), 1);
}

// void	ft_printf_f(va_list insertion)
// {
// 	printf("Here's a f!\n");
// }

// void	ft_printf_e(va_list insertion)
// {
// 	printf("Here's a e!\n");
// }

// void	ft_printf_g(va_list insertion)
// {
// 	printf("Here's a g!\n");
// }

// void	ft_printf_p(va_list insertion)
// {
// 	printf("Here's a p!\n");
// }

void	ft_printf_flag_dispatch(char *flags, int width, int precision, va_list insertion, int argument)
{
	void (*argument_list[127])(va_list);

	argument_list['d'] = ft_printf_di;
	// argument_list['i'] = ft_printf_di;
	// argument_list['o'] = ft_printf_o;
	// argument_list['x'] = ft_printf_x;
	// argument_list['u'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['p'] = ft_printf_p;
	printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	(*argument_list[argument])(insertion);
	// char (*flag_functions[5])(const char *restrict)
	// flag_functions[0] = char (*flag_minus)(const char *restrict);
	// flag_functions[1] = char (*flag_plus)(const char *restrict);
	// flag_functions[2] = char (*flag_zero)(const char *restrict);
	// flag_functions[3] = char (*flag_space)(const char *restrict);
	// flag_functions[4] = char (*flag_hash)(const char *restrict);
	// flag_functions[5] = '\0';
}