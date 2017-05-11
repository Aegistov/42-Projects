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

void	ft_printf_flag_dispatch(const char *restrict format, char *flags)
{
	char (*flag_functions[6])(const char *restrict)
	char (*flag_minus)(const char *restrict)
	char (*flag_plus)(const char *restrict)
	char (*flag_zero)(const char *restrict)
	char (*flag_space)(const char *restrict)
	char (*flag_hash)(const char *restrict)
}
