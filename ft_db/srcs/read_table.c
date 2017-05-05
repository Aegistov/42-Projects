/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:43:41 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 13:44:51 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include "vector.h"

t_list	*parse_entry(char *record_entry)
{
	char	*parsed;
	t_list	*row;
	int		column;
	char	*tmp;

	column = 0;
	row = NULL;
	parsed = strtok(record_entry, ",");
	while (parsed)
	{
		tmp = parsed;
		row = list_add_tail(row, tmp, strlen(parsed));
		parsed = strtok(NULL, ",\n");
		column++;
	}
	return (row);
}

int		read_table(FILE *table, vector *loaded_table)
{
	char	*record_entry;
	size_t	getline_return;
	size_t	nbytes;

	nbytes = 100;
	record_entry = NULL;
	if (loaded_table->items)
	{
		list_print(loaded_table->items[0]);
		vector_free(loaded_table);
	}
	while (1)
	{
		getline_return = getline(&record_entry, &nbytes, table);
		if (getline_return != strlen(record_entry))
			break ;
		vector_add_list(loaded_table, parse_entry(record_entry));
	}
	return (1);
}
