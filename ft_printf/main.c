/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:28:56 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 12:28:58 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	printf("%e\n", 5431.21);
	ft_printf("Test %-0+ #1345431.123454321d What about this? %s ...And characters: %c!\n", 90001, "I know how to print a string!", 'F');
}
