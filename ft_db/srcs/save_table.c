/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:46:05 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 15:57:26 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		save_table(vector *loaded_table, char *table_name)
{
	FILE	*modified_table;
	char	*record_entry;
	int		counter;

	counter = 0;
	modified_table = fopen("modified_table.csv", "w");
	record_entry = (char *)malloc(1000);
	while (counter < loaded_table->total)
	{
		record_entry = load_list(loaded_table->items[counter]);
		fprintf(modified_table, "%s", record_entry);
		counter++;
	}
	fclose(modified_table);
	remove(table_name);
	rename("modified_table.csv", table_name);
	return (1);
}
