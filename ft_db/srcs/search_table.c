/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:47:22 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 16:47:24 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	vector_search(vector *loaded_table, char *str)
{
	int	counter;

	counter = 0;
	while (counter <= loaded_table->total)
	{
		if (list_search(loaded_table->items[counter], str))
		{
			list_print(loaded_table->items[counter]);
			printf("\n");
		}
		counter++;
	}
}

int		search_table(vector *loaded_table)
{
	int		option;
	int		id;
	char	*field;

	printf("Choose Search Option\n(1) Search By ID\n(2)Search For Field\n");
	printf("Option: ");
	scanf("%d", &option);
	if (option == 1)
	{
		printf("ID#: ");
		scanf("%d", &id);
		list_print(loaded_table->items[id]);
		printf("\n");
	}
	else if (option == 2)
	{
		field = (char *)malloc(256);
		printf("Search For: ");
		scanf("%s", field);
		vector_search(loaded_table, field);
	}
	else
		printf("Invalid Input\n");
	return (1);
}
