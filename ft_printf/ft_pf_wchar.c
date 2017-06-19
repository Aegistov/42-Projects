/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 22:09:43 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/18 22:09:44 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pf_put_one_byte(wchar_t ch)
{
	ft_putchar_fd((unsigned int)ch, 1);
	return (1);
}

int		ft_pf_put_two_bytes(wchar_t ch)
{
	unsigned int	chr;

	chr = (unsigned int)ch;
	ft_putchar_fd(192 | (chr >> 6 & 63), 1);
	ft_putchar_fd(128 | (chr & 63), 1);
	return (2);
}

int		ft_pf_put_three_bytes(wchar_t ch)
{
	unsigned int	chr;

	chr = (unsigned int)ch;
	ft_putchar_fd(224 | (chr >> 12 & 63), 1);
	ft_putchar_fd(128 | (chr >> 6 & 63), 1);
	ft_putchar_fd(128 | (chr & 63), 1);
	return (3);
}

int		ft_pf_put_four_bytes(wchar_t ch)
{
	unsigned int	chr;

	chr = (unsigned int)ch;
	ft_putchar_fd(240 | (chr >> 18 & 63), 1);
	ft_putchar_fd(128 | (chr >> 12 & 63), 1);
	ft_putchar_fd(128 | (chr >> 6 & 63), 1);
	ft_putchar_fd(128 | (chr & 63), 1);
	return (4);
}

int		ft_pf_putwchar(wchar_t ch)
{
	unsigned int	chr;

	chr = (unsigned int)ch;
	if (chr <= 127)
		return (ft_pf_put_one_byte(ch));
	else if (chr <= 2047)
		return (ft_pf_put_two_bytes(ch));
	else if (chr <= 65535)
		return (ft_pf_put_three_bytes(ch));
	else
		return (ft_pf_put_four_bytes(ch));
}
