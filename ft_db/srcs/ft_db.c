/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:21:55 by yolabi            #+#    #+#             */
/*   Updated: 2017/05/05 13:45:49 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	main(void)
{
	int		menu_opt;
	FILE	*table;
	char	*table_name;
	vector	*loaded_table;

	loaded_table = (vector *)malloc(sizeof(vector));
	vector_init(loaded_table);
	menu_opt = 10;
	printf("Welcome to the DBMS\n\n");
	printf("Please listen closely, as our menu options have changed:\n");
	printf("Enter a selection number.\n");
	printf("1 - Help Page\n");
	printf("2 - Load Table\n");
	printf("3 - Display Table\n");
	printf("4 - Add to Table\n");
	printf("5 - Delete from Table\n");
	printf("6 - Modify in Table\n");
	printf("7 - Save Table\n");
	printf("8 - Search Table\n");
	printf("0 - Exit Program\n");
	while (1)
	{
		printf("Enter next menu option: ");
		scanf("%d", &menu_opt);
		if (menu_opt == 1)
		{
			help();
		}
		if (menu_opt == 2)
		{
			table_name = get_table_name();
			table = fopen(table_name, "r+");
			printf("File open\n");
			read_table(table, loaded_table);
			fclose(table);
		}
		if (menu_opt == 3)
		{
			printf("Displaying Table\n");
			display_loaded_table(loaded_table);
		}
		else if (menu_opt == 4)
		{
			add_record(loaded_table);
		}
		else if (menu_opt == 5)
		{
			del_record(loaded_table);
		}
		else if (menu_opt == 6)
		{
			modify_record(loaded_table);
		}
		else if (menu_opt == 7)
		{
			save_table(loaded_table, table_name);
		}
		else if (menu_opt == 8)
		{
			search_table(loaded_table);
		}
		else if (menu_opt == 0)
		{
			save_table(loaded_table, table_name);
			break ;
		}
	}
	return (0);
}
