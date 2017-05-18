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
#include <string.h>

int		main(void)
{
	// char 	*tmp;
	int		mylen;
	int		urlen;

	// tmp = strdup("Copy this string over");
	// tmp = ft_strfill(tmp, '4', 100);
	// printf("TMP: %s\n", tmp);
	// printf("Here's a string with stuff: %s\n", "Test case");
	mylen = ft_printf("Here's a test with a normal string: %s\nNow here's one with padding: %10s\nAnd now a string with /zero/ padding ;): %10s\nHere's one on the left...with padding...made of zeroes: %-10s\n", "Look a normal string!", "Look a string with padding!", "That's A Lot of Zero!", "I've got a large tail end!");
	urlen = printf("Here's a test with a normal string: %s\nNow here's one with padding: %10s\nAnd now a string with /zero/ padding ;): %10s\nHere's one on the left...with padding...made of zeroes: %-10s\n", "Look a normal string!", "Look a string with padding!", "That's A Lot of Zero!", "I've got a large tail end!");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", mylen, urlen);
	// ft_printf("Test %-0+ #1345431.123454321d What about this? %s ...And characters: %c!\n", 90001, "I know how to print a string!", 'F');
}
