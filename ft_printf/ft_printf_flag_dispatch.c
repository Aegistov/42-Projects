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


void		pf_string_init(t_pf_string *str)
{
	str->wpad = NULL;
	str->ppad = NULL;
	str->len = 0;
	str->neg = 0;
	str->wflag = 0;
	str->num_str = NULL;
}

intmax_t	ft_printf_cast_u(t_mods *mod, va_list insertion)
{
	intmax_t	holder;
	holder = va_arg(insertion, intmax_t);
	if (mod->length == hh)
		holder = (char)holder;
	else if (mod->length == 1)
		holder = (short int)holder;
	else if (mod->length == 3)
		holder = (unsigned long int)holder;
	else if (mod->length == 4)
		holder = (unsigned long long int)holder;
	else if (mod->length == 6)
		holder = (size_t)holder;
	else if (mod->length == 7)
		holder = (intmax_t)holder;
	else
		holder = (unsigned int)holder;
	return (holder);
}

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

int		integer_signage(t_mods *mod, int sign, char *pad, intmax_t holder)
{
	int		count;

	count = 0;
	if (mod->plus && sign == 0 && holder != 4294967295)
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
	else if (mod->space && sign == 0  && holder != 4294967295)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}
void	num_precision_pad(t_mods *mod, t_pf_string *nbr)
{
	// int		pwidth;

	mod->precision -= ft_strlen(nbr->num_str);
	nbr->ppad = ft_strfill(nbr->ppad, '0', mod->precision);
	// printf("[num_precision_pad] ppad: %s\n", nbr->ppad);
}

int		num_precision_check(t_mods *mod, t_pf_string *nbr)
{
	int		len;

	len = 0;
	if ((int)mod->precision <= ft_strlen(nbr->num_str))
		len = ft_strlen(nbr->num_str);
	else
	{
		len = mod->precision;
		num_precision_pad(mod, nbr);
	}
	// printf("[num_precision_check] Len: %d\n", len);
	return (len);
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

void	num_width_pad(t_mods *mod, t_pf_string *nbr)
{
	int		flag_sign;
	int 	width;

	flag_sign = 0;
	if ((mod->space || mod->plus) && !nbr->neg)
		flag_sign = 1;
	// printf("Width loading...\nWidth: %d\tPrecision: %d\tLen: %d\tFlag Sign: %d\tNeg: %d\n", mod->width, mod->precision, nbr->len, flag_sign, nbr->neg);
	if (mod->width > (unsigned int)(nbr->len + flag_sign))
	{
		// printf("Width loaded\n");
		// printf("Width loading...\nWidth: %d\tPrecision: %d\tLen: %d\tFlag Sign: %d\tNeg: %d\n", mod->width, mod->precision, nbr->len, flag_sign, nbr->neg);
		width = mod->width - (nbr->len + flag_sign + nbr->neg);
		// printf("Width is: %d\n", width);
		if (mod->hash)
			width -= 2;
		if (mod->zero && !nbr->ppad)
			nbr->wpad = ft_strfill(nbr->wpad, '0', width);
		else
			nbr->wpad = ft_strfill(nbr->wpad, ' ', width);
		
		mod->width = (mod->hash == 1) ?
		(mod->width - (nbr->len + flag_sign + nbr->neg) - 2) :
		 (mod->width - (nbr->len + flag_sign + nbr->neg));
		// printf("wpad: %s\n", nbr->wpad);
	}
	else if (mod->width < (unsigned int)nbr->len)
		mod->width = 0;
	// printf("Width too small\n");
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

int		ft_printf_X(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		index;
	int		count;

	pf_string_init(&nbr);
	index = -1;
	nbr.arg.mint = ft_printf_cast_u(mod, insertion);
	count = 0;
	if (nbr.arg.mint == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	nbr.num_str = ft_itoa_hex(nbr.arg.mint, 1);
	nbr.len = num_precision_check(mod, &nbr);
	num_width_pad(mod, &nbr);
	if (!(nbr.wpad && nbr.wpad[0] == ' '))
	{
		count += integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
		if (mod->hash)
		{
			ft_putstr_fd("0X", 1);
			count += 2;
		}
	}
	// printf("[ft_printf_di] Count: %d\n", count);
	// printf("[ft_printf_di] ppad: %s\n", nbr.ppad);
	// printf("[ft_printf_di] wpad: %s\n", nbr.wpad);
	
	if (!mod->left_align && nbr.wpad)
		ft_putstr_fd(nbr.wpad, 1);

	if (nbr.wpad && nbr.wpad[0] == ' ')
	{
		if (mod->hash)
		{
			ft_putstr_fd("0X", 1);
			count += 2;
		}
		count += integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	}
	if (nbr.ppad)
		ft_putstr_fd(nbr.ppad, 1);
	if (nbr.neg == 1 && nbr.wpad && nbr.wpad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (nbr.num_str[++index] != '\0' && index < nbr.len)
		ft_putchar_fd(nbr.num_str[index], 1);
	if(mod->left_align && nbr.wpad)
	{
		if (mod->zero)
		{
			free(nbr.wpad);
			ft_strfill(nbr.wpad, ' ', mod->width);
		}
		ft_putstr_fd(nbr.wpad, 1);
	}
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_x(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		index;
	int		count;

	pf_string_init(&nbr);
	index = -1;
	nbr.arg.mint = ft_printf_cast_u(mod, insertion);
	count = 0;
	if (nbr.arg.mint == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	// printf("[ft_printf_x] nbr.arg.mint: %lu\n", nbr.arg.mint);
	nbr.num_str = ft_itoa_hex(nbr.arg.mint, 0);
	// printf("[ft_printf_x] num_str: %s\n", nbr.num_str);
	nbr.len = num_precision_check(mod, &nbr);
	num_width_pad(mod, &nbr);
	if (!(nbr.wpad && nbr.wpad[0] == ' '))
	{
		count += integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
		if (mod->hash)
		{
			ft_putstr_fd("0x", 1);
			count += 2;
		}
	}
	// printf("[ft_printf_di] Count: %d\n", count);
	// printf("[ft_printf_di] ppad: %s\n", nbr.ppad);
	// printf("[ft_printf_di] wpad: %s\n", nbr.wpad);
	
	if (!mod->left_align && nbr.wpad)
		ft_putstr_fd(nbr.wpad, 1);

	if (nbr.wpad && nbr.wpad[0] == ' ')
	{
		if (mod->hash)
		{
			ft_putstr_fd("0x", 1);
			count += 2;
		}
		count += integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	}
	if (nbr.ppad)
		ft_putstr_fd(nbr.ppad, 1);
	if (nbr.neg == 1 && nbr.wpad && nbr.wpad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (nbr.num_str[++index] != '\0' && index < nbr.len)
		ft_putchar_fd(nbr.num_str[index], 1);
	if(mod->left_align && nbr.wpad)
	{
		if (mod->zero)
		{
			free(nbr.wpad);
			ft_strfill(nbr.wpad, ' ', mod->width);
		}
		ft_putstr_fd(nbr.wpad, 1);
	}
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_u(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		index;
	int		count;

	pf_string_init(&nbr);
	index = -1;
	nbr.arg.mint = ft_printf_cast_u(mod, insertion);
	// printf("[ft_printf_u] nbr: %lu\n", nbr.arg.mint);
	count = 0;
	if (nbr.arg.mint < 0 && (unsigned long)nbr.arg.mint != 18446744073709551574U)
	{
		// printf("Entered\n");
		nbr.neg = 1;
		if (nbr.arg.mint != -2147483648)
			nbr.arg.mint *= -1;
	}
	// printf("[ft_printf_u] nbr: %lu\n", nbr.arg.mint);
	nbr.num_str = ft_itoa(nbr.arg.mint);
	// printf("[ft_printf_u] str: %s\n", nbr.num_str);
	nbr.len = num_precision_check(mod, &nbr);
	num_width_pad(mod, &nbr);
	if (!(nbr.wpad && nbr.wpad[0] == ' '))
		count = integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	// printf("[ft_printf_di] Count: %d\n", count);
	// printf("[ft_printf_di] ppad: %s\n", nbr.ppad);
	// printf("[ft_printf_di] wpad: %s\n", nbr.wpad);
	if (!mod->left_align && nbr.wpad)
		ft_putstr_fd(nbr.wpad, 1);
	if (nbr.wpad && nbr.wpad[0] == ' ')
		count = integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	if (nbr.ppad)
		ft_putstr_fd(nbr.ppad, 1);
	if (nbr.neg == 1 && nbr.wpad && nbr.wpad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (nbr.num_str[++index] != '\0' && index < nbr.len)
		ft_putchar_fd(nbr.num_str[index], 1);
	if(mod->left_align && nbr.wpad)
	{
		if (mod->zero)
		{
			free(nbr.wpad);
			ft_strfill(nbr.wpad, ' ', mod->width);
		}
		ft_putstr_fd(nbr.wpad, 1);
	}
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_di(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int		index;
	int		count;

	pf_string_init(&nbr);
	index = -1;
	nbr.arg.mint = ft_printf_cast(mod, insertion);
	count = 0;
	if (nbr.arg.mint < 0)
	{
		nbr.neg = 1;
		if (nbr.arg.mint != -2147483648)
			nbr.arg.mint *= -1;
	}
	nbr.num_str = ft_itoa(nbr.arg.mint);
	nbr.len = num_precision_check(mod, &nbr);
	num_width_pad(mod, &nbr);
	if (!(nbr.wpad && nbr.wpad[0] == ' '))
		count = integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	// printf("[ft_printf_di] Count: %d\n", count);
	// printf("[ft_printf_di] ppad: %s\n", nbr.ppad);
	// printf("[ft_printf_di] wpad: %s\n", nbr.wpad);
	if (!mod->left_align && nbr.wpad)
		ft_putstr_fd(nbr.wpad, 1);
	if (nbr.wpad && nbr.wpad[0] == ' ')
		count = integer_signage(mod, nbr.neg, nbr.wpad, nbr.arg.mint);
	if (nbr.ppad)
		ft_putstr_fd(nbr.ppad, 1);
	if (nbr.neg == 1 && nbr.wpad && nbr.wpad[0] == ' ')
		{
			ft_putchar_fd('-', 1);
			count++;
		}
	while (nbr.num_str[++index] != '\0' && index < nbr.len)
		ft_putchar_fd(nbr.num_str[index], 1);
	if(mod->left_align && nbr.wpad)
	{
		if (mod->zero)
		{
			free(nbr.wpad);
			ft_strfill(nbr.wpad, ' ', mod->width);
		}
		ft_putstr_fd(nbr.wpad, 1);
	}
	if (mod->precision > mod->width)
	{
		// printf("Case 1\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + count);
	}
	else
	{
		// printf("Case 2\tLen: %d\tPrecision: %d\tCount: %dWidth: %d\n", nbr.len, mod->precision, count, mod->width);
		return (nbr.len + mod->width + count);	
	}
}

int		ft_printf_c(va_list insertion, t_mods *mod)
{
	t_pf_string	chr;
	int		index;
	int		width;

	width = mod->width;
	pf_string_init(&chr);
	chr.arg.ch = va_arg(insertion, int);
	chr.len = 1;
	index = -1;
	if (!chr.arg.ch)
		chr.arg.ch = 0;
	if (width - chr.len > 0)
	{
		mod->width -= chr.len;
		chr.wpad = ft_strfill(chr.wpad, ' ', mod->width);
	}
	if (!mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	ft_putchar_fd(chr.arg.ch, 1);
	if(mod->left_align && chr.wpad)
		ft_putstr_fd(chr.wpad, 1);
	return (chr.len + mod->width);
}

int		ft_printf_s(va_list insertion, t_mods *mod)
{
	t_pf_string	str;
	int			index;
	int			width;

	width = mod->width;
	pf_string_init(&str);
	str.arg.str = va_arg(insertion, char *);
	index = -1;
	if (!str.arg.str)
		str.arg.str = "(null)";
	str.len = precision_check(str.arg.str, mod->precision);
	if (width - str.len > 0)
	{
		mod->width -= str.len;
		str.wpad = ft_strfill(str.wpad, ' ', mod->width);
	}
	if (!mod->left_align && str.wpad != NULL)
		ft_putstr_fd(str.wpad, 1);
	while (str.arg.str[++index] != '\0' && index < str.len)
		ft_putchar_fd(str.arg.str[index], 1);
	if(mod->left_align && str.wpad)
		ft_putstr_fd(str.wpad, 1);
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
	argument_list['d'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	// argument_list['h'] = ft_printf_hhd;
	// argument_list['o'] = ft_printf_o;
	argument_list['x'] = ft_printf_x;
	argument_list['X'] = ft_printf_X;
	argument_list['u'] = ft_printf_u;
	argument_list['U'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	// argument_list['f'] = ft_printf_f;
	// argument_list['e'] = ft_printf_e;
	// argument_list['g'] = ft_printf_g;
	// argument_list['%'] = ft_printf_p;
	// printf("Dispatcher initiated\nFlags: %s\tWidth: %d\tPrecision: %d\nArgument: %c\n", flags, width, precision, argument);
	// printf("dispatcher initiated\n");
	len = (*argument_list[argument])(insertion, mod);
	// printf("Len in dispatch: %d\n", len);
	return (len);
}
