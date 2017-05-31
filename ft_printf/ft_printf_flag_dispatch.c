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

intmax_t	ft_printf_cast(t_mods *mod, va_list insertion)
{
	intmax_t	holder;
	// printf("[ft_printf_cast]initiated...\n");
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
		{
			// printf("hh-case\n");
			return((char)holder);
		}
	else if (mod->length == h)
		return ((short)holder);
	else if (mod->length == l)
		return ((long)holder);
	else if (mod->length == ll)
		return ((long long)holder);
	return ((int)holder);
}

int		integer_signage(t_mods *mod, int sign, char *pad, int holder)
{
	int		count;

	count = 0;
	if (mod->plus && sign == 0)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (sign == 1 && holder != -2147483648)
	{
		if (pad && pad[0] != ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
		else if (!pad)
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	}
	else if (mod->space && sign == 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int		precision_check(char *str, int precision)
{
	int		len;

	len = 0;
	if (precision > 0)
	{
		while (len < precision)
		{
			if (str[len] == '\0')
				break ;
			len++;
		}
	}
	else
		len = ft_strlen(str);
	return (len);
}

char	*padding(t_mods *mod, int len, int sign)
{
	char	*pad;
	int		flag_sign;
	int 	width;

	width = mod->width;
	flag_sign = 0;
	pad = NULL;
	if ((mod->space || mod->plus) && sign == 0)
		flag_sign = 1;
	if (width - len - flag_sign > 0)
	{
		// printf("Width: %d\tLen: %d\tflag_sign: %d\n", *width, len, flag_sign);
		mod->width -= (len + flag_sign + sign);
		if (mod->zero)
			pad = ft_strfill(pad, '0', mod->width);
		else
			pad = ft_strfill(pad, ' ', mod->width);
		// *width -= len - flag_sign;
		// printf("Width in padding: %d\nPadding: %s\n", *width, pad);
	}
	return (pad);
}

// int		ft_printf_hhd(va_list insertion, char *flags, int width, int precision)
// {
// 	int		count;
// 	int		holder;

// 	// if ()
// 	holder = va_arg(insertion, signed char);
// 	printf("I'm using them! %s%d%d\n", flags, width, precision);
// 	count = 0;

// 	return (count);
// }

int		ft_printf_di(va_list insertion, t_mods *mod)
{
	int 	holder;
	char	*number_str;
	char	*pad;
	int		len;
	int		index;
	int 	sign;
	int		count;

	// pad = NULL;
	len = 0;
	index = -1;
	if (mod->length != none)
	{
		holder = ft_printf_cast(mod, insertion);
		// printf("%d\n", holder);
	}
	else
		holder = va_arg(insertion, int);
	sign = 0;
	count = 0;
	if (holder < 0)
	{
		sign = 1;
		if (holder != -2147483648)
			holder *= -1;
	}
	number_str = ft_itoa(holder);
	len = precision_check(number_str, mod->precision);
	pad = padding(mod, len, sign);
	count = integer_signage(mod, sign, pad, holder);
	if (!mod->left_align && pad)
		ft_putstr_fd(pad, 1);
	if (sign == 1 && pad && pad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (number_str[++index] != '\0' && index < len)
		ft_putchar_fd(number_str[index], 1);
	if(mod->left_align && pad)
	{
		if (mod->zero)
		{
			free(pad);
			ft_strfill(pad, ' ', mod->width);
		}
		ft_putstr_fd(pad, 1);
	}
	return (len + mod->width + count);	
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

int		ft_printf_c(va_list insertion, t_mods *mod)
{
	char	*pad;
	char	c;
	int		len;
	int		index;
	int		width;

	width = mod->width;
	pad = NULL;
	c = va_arg(insertion, int);
	len = 1;
	index = -1;
	if (!c)
		c = 0;
	if (width - len > 0)
	{
		mod->width -= len;
		pad = ft_strfill(pad, ' ', mod->width);
	}
	if (!mod->left_align && pad)
		ft_putstr_fd(pad, 1);
	ft_putchar_fd(c, 1);
	if(mod->left_align && pad)
		ft_putstr_fd(pad, 1);
	return (len + mod->width);
}

int		ft_printf_s(va_list insertion, t_mods *mod)
{
	char	*pad;
	char	*str;
	int		len;
	int		index;
	int		width;

	width = mod->width;
	pad = NULL;
	str = va_arg(insertion, char *);
	len = 0;
	index = -1;
	if (!str)
		str = "(null)";
	len = precision_check(str, mod->precision);
	// printf("LEN: %d\nWidth: %d\nWidth - len = %d\n", len, mod->width, mod->width - len);
	if (width - len > 0)
	{
		// printf("Editing width: %d\n", mod->width);
		mod->width -= len;
		// printf("%d\n", mod->width);
		pad = ft_strfill(pad, ' ', mod->width);
	}
	if (!mod->left_align && pad)
		ft_putstr_fd(pad, 1);
	while (str[++index] != '\0' && index < len)
		ft_putchar_fd(str[index], 1);
	if(mod->left_align && pad)
		ft_putstr_fd(pad, 1);
	// printf("LEN: %d\nWidth: %d\n", len, mod->width);
	return (len + mod->width);
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

int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument)
{
	int (*argument_list[127])(va_list, t_mods *);
	int	len;
	argument_list['d'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	// argument_list['h'] = ft_printf_hhd;
	// argument_list['o'] = ft_printf_o;
	// argument_list['x'] = ft_printf_x;
	// argument_list['u'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['p'] = ft_printf_p;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	len = (*argument_list[argument])(insertion, mod);
	// char (*flag_functions[5])(const char *restrict)
	// flag_functions[0] = char (*flag_minus)(const char *restrict);
	// flag_functions[1] = char (*flag_plus)(const char *restrict);
	// flag_functions[2] = char (*flag_zero)(const char *restrict);
	// flag_functions[3] = char (*flag_space)(const char *restrict);
	// flag_functions[4] = char (*flag_hash)(const char *restrict);
	// flag_functions[5] = '\0';
	// printf("Len in dispatch: %d\n", len);
	return (len);
}
