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

int		basic_test_for_strings(void)
{
	int		my_printf;
	int		base_printf;

	printf("[basic_test_for_strings]\n\n");
	my_printf = ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	base_printf = printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		width_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[width_test_for_number]\n\n");
	my_printf = ft_printf("%5d\n", 42);
	base_printf = printf("%5d\n", 42);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		small_width_big_precision_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[width_precision_test_for_number]\n\n");
	my_printf = ft_printf("%4.15d\n", 42);
	base_printf = printf("%4.15d\n", 42);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		big_width_small_precision_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[big_width_small_precision_test_for_number]\n\n");
	my_printf = ft_printf("%10.5d\n", 4242);
	base_printf = printf("%10.5d\n", 4242);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		sign_big_width_small_precision_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[sign_big_width_small_precision_test_for_number]\n\n");
	my_printf = ft_printf("%+10.5d\n", 4242);
	base_printf = printf("%+10.5d\n", 4242);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		zero_width_precision_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[zero_width_precision_test_for_number]\n\n");
	my_printf = ft_printf("%03.2d\n", 0);
	base_printf = printf("%03.2d\n", 0);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		empty_precision_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[empty_precision_test_for_number]\n\n");
	my_printf = ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	base_printf = printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		basic_unsigned_long_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[basic_unsigned_long_test_for_number]\n\n");
	my_printf = ft_printf("%lu\n", "-42");
	base_printf = printf("%lu\n", (unsigned long)-42);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		hexadecimal_long_test_for_number(void)
{
	int		my_printf;
	int		base_printf;

	printf("[hexadecimal_long_test_for_number]\n\n");
	my_printf = ft_printf("%lx\n", 4294967296);
	base_printf = printf("%lx\n", 4294967296);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_precision_d_higher_min_width_neg(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_precision_d_higher_min_width_neg]\n\n");
	my_printf = ft_printf("%15.4d\n", -42);
	base_printf = printf("%15.4d\n", -42);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_precision_d_zero_value(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_precision_d_zero_value]\n\n");
	my_printf = ft_printf("%.d, %.0dEnd\n", 0, 0);
	base_printf = printf("%.d, %.0dEnd\n", 0, 0);
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
	// printf("Difference: %d\n", test_hhd_basic());
	// printf("Difference: %d\n", basic_test_for_strings());
	// printf("Difference: %d\n", width_test_for_number());
	// printf("Difference: %d\n", small_width_big_precision_test_for_number());
	// printf("Difference: %d\n", big_width_small_precision_test_for_number());
	// printf("Difference: %d\n", sign_big_width_small_precision_test_for_number());
	// printf("Difference: %d\n", zero_width_precision_test_for_number());
	// printf("Difference: %d\n", empty_precision_test_for_number());
	// printf("Difference: %d\n", basic_unsigned_long_test_for_number());
	// printf("Difference: %d\n", hexadecimal_long_test_for_number());
	// printf("Difference: %d\n", test_precision_d_higher_min_width_neg());
	printf("Difference: %d\n", test_precision_d_zero_value());
}
