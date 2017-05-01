/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:21:55 by yolabi            #+#    #+#             */
/*   Updated: 2017/04/27 19:02:15 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	main(void)
{
	int		menu_opt;
	FILE	*table;
	char	*table_name;
	char	*record;
	size_t	nbytes = 100;

	menu_opt = 10;
	record = (char *)malloc(nbytes + 1);
	printf("Welcome to the DBMS\n\n");
	printf("Please listen closely, as our menu options have changed:\n");
	printf("Enter a selection number.\n");
	printf("1 - Select Database.\n");
	printf("2 - Select Table\n");
	printf("3 - Display Table\n");
	printf("4 - Add to Table\n");
	printf("0 - Exit Program\n");
	while (1)//(menu_opt != 0)
	{
		printf("Enter next menu option: ");
		scanf("%d", &menu_opt);
		if (menu_opt == 3)
		{
			table_name = open_table();
			table = fopen(table_name, "r");
			read_file(table);
		}
		else if (menu_opt == 4)
		{
			table_name = open_table();
			printf("pre-open\n");
			table = fopen(table_name, "r");
			// printf("open success\n");
			add_record(table, table_name);
			free(table_name);
			fclose(table);
		}
		else if (menu_opt == 0)
			break ;
	}
	fclose(table);
	return (0);
}
