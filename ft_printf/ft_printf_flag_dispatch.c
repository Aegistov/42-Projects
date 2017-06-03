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
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
		holder = (char)holder;
	else if (mod->length == 1)
		holder = (short int)holder;
	else if (mod->length == 3)
		holder = (long int)holder;
	else if (mod->length == 4)
		holder = (long long int)holder;
	else if (mod->length == 6)
		holder = (size_t)holder;
	else if (mod->length == 7)
		holder = (intmax_t)holder;
	else
		holder = (int)holder;
	return (holder);
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
	// printf("Len in precision_check: %d\n", len);
	return (len);
}

char	*padding_for_num(t_mods *mod, int len, int sign)
{
	char	*pad;
	int		flag_sign;
	int 	width;

	if (mod->width > mod->precision)
		width = mod->width;
	else
		width = mod->precision;
	flag_sign = 0;
	pad = NULL;
	if ((mod->space || mod->plus) && sign == 0)
		flag_sign = 1;
	if (width - len - flag_sign > 0)
	{
		// printf("Width: %d\tLen: %d\tflag_sign: %d\n", *width, len, flag_sign);
		mod->width -= (len + flag_sign + sign);
		width -= (len + flag_sign + sign);
		if (mod->zero || (mod->precision > mod->width))
			pad = ft_strfill(pad, '0', width);
		else
			pad = ft_strfill(pad, ' ', width);
		// *width -= len - flag_sign;
		// printf("Width in padding: %d\nPadding: %s\n", *width, pad);
	}
	return (pad);
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
	intmax_t 	holder;
	char	*number_str;
	char	*pad;
	int		len;
	int		index;
	int 	sign;
	int		count;

	// pad = NULL;
	len = 0;
	index = -1;
	holder = ft_printf_cast(mod, insertion);
	sign = 0;
	count = 0;
	if (holder < 0)
	{
		sign = 1;
		if (holder != -2147483648)
			holder *= -1;
	}
	number_str = ft_itoa(holder);
	// printf("Number: %s\n", number_str);
	len = precision_check(number_str, mod->precision);
	pad = padding_for_num(mod, len, sign);
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
	// char	*pad;
	// char	*str;
	int		len;
	t_pf_string	str;
	int			index;
	int			width;

	// if (!(str = (t_pf_string *)ft_memalloc(sizeof(t_pf_string))))
	// 	return (-1);
	width = mod->width;
	len = str.len;
	str.arg.str = va_arg(insertion, char *);
	printf("String: %s\n", str.arg.str);
	index = -1;
	printf("null check\n");
	if (!str.arg.str)
		str.arg.str = "(null)";
	printf("len loading\n");
	str.len = precision_check(str.arg.str, mod->precision);
	printf("LEN: %d\nWidth: %d\nWidth - len = %d\n", len, mod->width, mod->width - len);
	if (width - str.len > 0)
	{
		printf("Editing width: %d\n", mod->width);
		mod->width -= str.len;
		// printf("%d\n", mod->width);
		str.pad = ft_strfill(str.pad, ' ', mod->width);
	}
	printf("pad check\n");
	if (str.pad == NULL)
		printf("NULL");
	printf("next stage: %s\n", str.pad);
	if (!mod->left_align && str.pad != NULL)
	{
		printf("entered\n");
		// p
		ft_putstr_fd(str.pad, 1);
		printf("complete\n");
	}
	printf("arguement printing\n");
	while (str.arg.str[++index] != '\0')
	{
		// printf("Char: %c\n", str.arg.str[index]);
		ft_putchar_fd(str.arg.str[index], 1);
	}
	// printf("Char out of loop: %c\n", str.arg.str[index]);
	if(mod->left_align && str.pad)
		ft_putstr_fd(str.pad, 1);
	// printf("LEN: %d\nWidth: %d\n", len, mod->width);
	return (str.len + mod->width);
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
	// argument_list['d'] = ft_printf_di;
	// argument_list['i'] = ft_printf_di;
	// argument_list['h'] = ft_printf_hhd;
	// argument_list['o'] = ft_printf_o;
	// argument_list['x'] = ft_printf_x;
	// argument_list['u'] = ft_printf_di;
	// argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['%'] = ft_printf_p;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	// printf("dispatcher initiated\n");
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
