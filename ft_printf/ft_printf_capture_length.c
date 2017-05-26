/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capture_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:30:30 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/25 22:30:31 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_capture_length(const char *restrict format, char *length, int index)
{
	int		count;

	count = 0;
	while (format[index] == 'h' || format[index] == 'l' || format[index] == 'L' || format[index] == 'z' || format[index] == 'j' || format[index] == 't')
	{
		length[count] = format[index];
		length[count + 1] = '\0';
		printf("Format: %c\nLength: %s\n", format[index], length);
		index += 1;
		count++;
	}
	return (count);
}
