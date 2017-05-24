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

int		integer_signage(char *flags, int sign, char *pad, int holder)
{
	int		count;

	count = 0;
	if (ft_strchr(flags, '+') && sign == 0)
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
	else if (ft_strchr(flags, ' ') && sign == 0)
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

char	*padding(int *width, char *flags, int len, int sign)
{
	char	*pad;
	int		flag_sign;

	flag_sign = 0;
	pad = NULL;
	if ((ft_strchr(flags, ' ') || ft_strchr(flags, '+')) && sign == 0)
		flag_sign = 1;
	if (*width - len - flag_sign > 0)
	{
		// printf("Width: %d\tLen: %d\tflag_sign: %d\n", *width, len, flag_sign);
		*width -= (len + flag_sign + sign);
		if (ft_strchr(flags, '0'))
			pad = ft_strfill(pad, '0', *width);
		else
			pad = ft_strfill(pad, ' ', *width);
		// *width -= len - flag_sign;
		// printf("Width in padding: %d\nPadding: %s\n", *width, pad);
	}
	return (pad);
}

int		ft_printf_di(va_list insertion, char *flags, int width, int precision)
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
	len = precision_check(number_str, precision);
	pad = padding(&width, flags, len, sign);
	count = integer_signage(flags, sign, pad, holder);
	if (!ft_strchr(flags, '-') && pad)
		ft_putstr_fd(pad, 1);
	if (sign == 1 && pad && pad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (number_str[++index] != '\0' && index < len)
		ft_putchar_fd(number_str[index], 1);
	if(ft_strchr(flags, '-') && pad)
	{
		if (ft_strchr(pad, '0'))
		{
			free(pad);
			ft_strfill(pad, ' ', width);
		}
		ft_putstr_fd(pad, 1);
	}
	return (len + width + count);	
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

int		ft_printf_c(va_list insertion, char *flags, int width, int precision)
{
	char	*pad;
	char	c;
	int		len;
	int		index;

	pad = NULL;
	c = va_arg(insertion, int);
	len = 1;
	index = -1;
	precision = 0;
	if (!c)
		c = 0;
	if (width - len > 0)
	{
		width -= len;
		pad = ft_strfill(pad, ' ', width);
	}
	if (!ft_strchr(flags, '-') && pad)
		ft_putstr_fd(pad, 1);
	ft_putchar_fd(c, 1);
	if(ft_strchr(flags, '-') && pad)
		ft_putstr_fd(pad, 1);
	return (len + width);
}

int		ft_printf_s(va_list insertion, char *flags, int width, int precision)
{
	char	*pad;
	char	*str;
	int		len;
	int		index;

	pad = NULL;
	str = va_arg(insertion, char *);
	len = 0;
	index = -1;
	if (!str)
		str = "(null)";
	len = precision_check(str, precision);
	if (width - len > 0)
	{
		width -= len;
		pad = ft_strfill(pad, ' ', width);
	}
	if (!ft_strchr(flags, '-') && pad)
		ft_putstr_fd(pad, 1);
	while (str[++index] != '\0' && index < len)
		ft_putchar_fd(str[index], 1);
	if(ft_strchr(flags, '-') && pad)
		ft_putstr_fd(pad, 1);
	return (len + width);
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

int		ft_printf_flag_dispatch(char *flags, int width, int precision, va_list insertion, int argument)
{
	int (*argument_list[127])(va_list, char *, int, int);
	int	len;
	argument_list['d'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	// argument_list['o'] = ft_printf_o;
	// argument_list['x'] = ft_printf_x;
	// argument_list['u'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['p'] = ft_printf_p;
	precision += 0;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	len = (*argument_list[argument])(insertion, flags, width, precision);
	// char (*flag_functions[5])(const char *restrict)
	// flag_functions[0] = char (*flag_minus)(const char *restrict);
	// flag_functions[1] = char (*flag_plus)(const char *restrict);
	// flag_functions[2] = char (*flag_zero)(const char *restrict);
	// flag_functions[3] = char (*flag_space)(const char *restrict);
	// flag_functions[4] = char (*flag_hash)(const char *restrict);
	// flag_functions[5] = '\0';
	return (len);
}
