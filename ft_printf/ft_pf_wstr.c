/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 22:43:10 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/18 22:43:11 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pf_putwstr(wchar_t *str)
{
	if (!str)
		ft_printf("(null)");
	while (*str)
	{
		ft_pf_putwchar(*str);
		str++;
	}
}

int		ft_pf_wchar_len(wchar_t ch)
{
	unsigned int	chr;

	chr = (unsigned int)ch;
	if (chr <= 127)
		return (1);
	else if (chr <= 2047)
		return (2);
	else if (chr <= 65535)
		return (3);
	else
		return (4);
}

int		ft_pf_wstr_len(wchar_t *str)
{
	int		len;

	len = 0;
	// printf("Getting length\n");
	if (!str)
	{
		// printf("Null\n");
		return (ft_printf("(null)"));
	}
	while (*str)
	{
		len += ft_pf_wchar_len(*str);
		str++;
	}
	return (len);
}
