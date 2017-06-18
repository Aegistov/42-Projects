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
#include <limits.h>

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

int		zeroFlag_plusFlag_minWidth(void)
{
	int		my_printf;
	int		base_printf;

	printf("[zeroFlag_plusFlag_minWidth]\n\n");
	my_printf = ft_printf("{%+03d}\n", 12);
	base_printf = printf("{%+03d}\n", 12);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		octalUppercase_precision_sharpFlag_zeroValue(void)
{
	int		my_printf;
	int		base_printf;

	printf("[octalUppercase_precision_sharpFlag_zeroValue]\n\n");
	my_printf = ft_printf("%#.O\n", 0);
	base_printf = printf("%#.O\n", 0);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_zu_unsign_long_long_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_zu_unsign_long_long_max]\n\n");
	my_printf = ft_printf("%zu, %zu\n", 0, (unsigned long)ULLONG_MAX);
	base_printf = printf("%zu, %zu\n", (unsigned long)0, (unsigned long)ULLONG_MAX);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_jd_llong_min(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_jd_llong_min]\n\n");
	my_printf = ft_printf("%jd\n", (long long)-9223372036854775807);
	base_printf = printf("%jd\n", (intmax_t)-9223372036854775807);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		basics_150(void)
{
	int		my_printf;
	int		base_printf;
	long long int nbr = -9223372036854775807 - 1;

	printf("[basics_150]\n\n");
	my_printf = ft_printf("%lld\n", nbr);
	base_printf = printf("%lld\n", nbr);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_err_zd_up_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_err_zd_up_max]\n\n");
	my_printf = ft_printf("%zD, %zD\n", 0, (unsigned short)65535);
	base_printf = printf("%zD, %zD\n", 0, (unsigned short)65535);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_simple(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_simple]\n\n");
	my_printf = ft_printf("%S\n", L"米");
	base_printf = printf("%S\n", L"米");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_ju_unsign_long_long_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_ju_unsign_long_long_max]\n\n");
	my_printf = ft_printf("%ju, %ju\n", (uintmax_t)0, 18446744073709551615U);
	base_printf = printf("%ju, %ju\n", (uintmax_t)0, 18446744073709551615U);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_hho_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_hho_max]\n\n");
	my_printf = ft_printf("%hho, %hho\n", (unsigned char)0, (unsigned char)255);
	base_printf = printf("%hho, %hho\n", (unsigned char)0, (unsigned char)255);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_hhu_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_hhu_max]\n\n");
	my_printf = ft_printf("%hhu, %hhu\n", (unsigned char)0, (unsigned char)255);
	base_printf = printf("%hhu, %hhu\n", (unsigned char)0, (unsigned char)255);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_hhx_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_hhx_max]\n\n");
	my_printf = ft_printf("%hhx, %hhx\n", (unsigned char)0, (unsigned char)255);
	base_printf = printf("%hhx, %hhx\n", (unsigned char)0, (unsigned char)255);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_err_hho_up_max(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_err_hho_up_max]\n\n");
	my_printf = ft_printf("%hhO, %hhO\n", (unsigned char)0, (short int)65535);
	base_printf = printf("%hhO, %hhO\n", (unsigned char)0, (unsigned char)65535);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_int_pointer(void)
{
	int		my_printf;
	int		base_printf;
	int 	i;

	printf("[test_int_pointer]\n\n");
	my_printf = ft_printf("%p\n", &i);
	base_printf = printf("%p\n", &i);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_zero(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_zero]\n\n");
	my_printf = ft_printf("%p\n", (void *)0);
	base_printf = printf("%p\n", (void *)0);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		pZero_minus13MinWidth(void)
{
	int		my_printf;
	int		base_printf;

	printf("[pZero_minus13MinWidth]\n\n");
	my_printf = ft_printf("{%-13p}\n", &strlen);
	base_printf = printf("{%-13p}\n", &strlen);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		basics_047(void)
{
	int		my_printf;
	int		base_printf;

	printf("[basics_047](@moulitest: %%.x %%.0x)\n\n");
	my_printf = ft_printf("@moulitest: %.x %.0xEND\n", 0, 0);
	base_printf = printf("@moulitest: %.x %.0xEND\n", 0, 0);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		basics_190(void)
{
	int		my_printf;
	int		base_printf;

	printf("[basics_190]('%%lu\\n', '-42')\n\n");
	my_printf = ft_printf("%lu\n", (unsigned long)"-42");
	base_printf = printf("%lu\n", (unsigned long)"-42");
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		test_hhd(void)
{
	int		my_printf;
	int		base_printf;

	printf("[test_hhd]\n\n");
	my_printf = ft_printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
	base_printf = printf("%hhd - %hhd", SHRT_MAX - 42,  SHRT_MAX - 4200);
	printf("Return Values:\nft_printf: %d\tprintf: %d\n", my_printf, base_printf);
	printf("\n\n");
	return (base_printf - my_printf);
}

int		basics_mtest(void)
{
	int		my_printf;
	int		base_printf;

	printf("[basics_mtest]\n\n");
	my_printf = ft_printf("002147483647-21474836482147483647-2147483648%d\n", 0000042);
	base_printf = printf("002147483647-21474836482147483647-2147483648%d\n", 0000042);
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
	// printf("Difference: %d\n", test_precision_d_zero_value());
	// printf("Difference: %d\n", zeroFlag_plusFlag_minWidth());
	// printf("Difference: %d\n", octalUppercase_precision_sharpFlag_zeroValue());
	// printf("Difference: %d\n", test_zu_unsign_long_long_max());
	// printf("Difference: %d\n", test_hhu_max());
	// printf("Difference: %d\n", test_jd_llong_min());
	// printf("Difference: %d\n", basics_150());
	// printf("Difference: %d\n", test_err_zd_up_max());
	// printf("Difference: %d\n", test_simple());
	// printf("Difference: %d\n", test_ju_unsign_long_long_max());
	// printf("Difference: %d\n", test_hho_max());
	// printf("Difference: %d\n", test_hhu_max());
	// printf("Difference: %d\n", test_hhx_max());
	// printf("Difference: %d\n", test_err_hho_up_max());
	// printf("Difference: %d\n", test_int_pointer());
	// printf("Difference: %d\n", test_zero());
	// printf("Difference: %d\n", pZero_minus13MinWidth());
	// printf("Difference: %d\n", basics_047());
	// printf("Difference: %d\n", basics_190());
	// printf("Difference: %d\n", basics_mtest());
	printf("Difference: %d\n", test_hhd());

}
