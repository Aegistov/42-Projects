/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:36:42 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 11:36:43 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"


int		ft_printf(const char *restrict format, ...)
{
	ft_printf_parse(format);
	ft_putchar_fd(*format, 1);
	return (1);
}
