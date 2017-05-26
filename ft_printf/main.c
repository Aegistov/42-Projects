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

int		test_hhd_basic(void)
{
	int		my_printf;
	int		base_printf;

	//hhd takes an int and does the modulo opertaion on it to return the ascii character

	printf("[test_hhd_basic]\n\n");
	base_printf = printf("%hhd\nAs a char: %c\n", (signed char)2147483275, (signed char)90);
	my_printf = ft_printf("%hhd\n", (signed char)-128);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_null_argument(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_null_argument]\n\n");
	printf("base\n");
	base_printf = printf("@moulitest: %s", NULL);
	printf("mine\n");
	my_printf = ft_printf("@moulitest: %s", NULL);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		precision_test_for_empty_string(void)
{
	int		my_printf;
	int		base_printf;

	printf("[precision_test_for_empty_string]\n\n");
	my_printf = ft_printf("Basic Test 1:\n%.5s\n", "Here's a string with than 5 characters");
	base_printf = printf("%.2s is a string", "");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		precision_test_for_strings(void)
{
	int		my_printf;
	int		base_printf;

	printf("[precision_test_for_strings]\n\n");
	my_printf = ft_printf("%.2s is a string", "this");
	base_printf = printf("%.2s is a string", "this");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		main(void)
{
	// char 	*tmp;
	// int		mylen;
	// int		urlen;

	// mylen = 0;
	// tmp = strdup("Copy this string over");
	// tmp = ft_strfill(tmp, '4', 100);
	// printf("TMP: %s\n", tmp);
	// printf("Here's a string with stuff: %s\n", "Test case");
	// mylen = ft_printf("Here's a test with a normal string: %s\nNow here's one with padding: %50.2s\nAnd now a string with /zero/ padding ;): %10s\nHere's one on the left...with padding...made of zeroes: %-10s\n", "Look a normal string!", "Look a string with padding!", "That's A Lot of Zero!", "I've got a large tail end!");
	// urlen = printf("Here's a test with a normal string: %s\nNow here's one with padding: %50.2s\nAnd now a string with /zero/ padding ;): %10s\nHere's one on the left...with padding...made of zeroes: %-10s\n", "Look a normal string!", "Look a string with padding!", "That's A Lot of Zero!", "I've got a large tail end!");
	// printf("Return Values:\nft_printf: %d\tprintf: %d\n", mylen, urlen);
	// ft_printf("Test %-0+ #1345431.123454321d What about this? %s ...And characters: %c!\n", 90001, "I know how to print a string!", 'F');



	// printf("Difference: %d\n", precision_test_for_strings());
	// printf("Difference: %d\n", precision_test_for_empty_string());
	// printf("Difference: %d\n", test_null_argument());
	printf("Difference: %d\n", test_hhd_basic());



}
