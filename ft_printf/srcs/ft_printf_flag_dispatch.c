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

char	(*flag_minus)(const char *restrict);
char	(*flag_plus)(const char *restrict);
char	(*flag_zero)(const char *restrict);
char	(*flag_space)(const char *restrict);
char	(*flag_hash)(const char *restrict);

void	ft_printf_flag_dispatch(const char *restrict format, char *flags)
{
	char (*flag_functions[5])(const char *restrict)
	flag_functions[0] = char (*flag_minus)(const char *restrict);
	flag_functions[1] = char (*flag_plus)(const char *restrict);
	flag_functions[2] = char (*flag_zero)(const char *restrict);
	flag_functions[3] = char (*flag_space)(const char *restrict);
	flag_functions[4] = char (*flag_hash)(const char *restrict);
	flag_functions[5] = '\0';
}
