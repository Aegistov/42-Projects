/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:08:12 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 14:11:08 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*itostr(int number)
{
	int		len;
	char	*string;

	len = snprintf(NULL, 0, "%d", number);
	string = (char *)malloc(sizeof(int) * (len + 1));
	snprintf(string, len + 1, "%d", number);
	return (string);
}

t_list	*store_input(vector *loaded_table)
{
	char	*cell_entry;
	t_list	*tmp;
	t_list	*record;
	char	*id;

	record = NULL;
	cell_entry = (char *)malloc(100);
	tmp = loaded_table->items[0];
	id = itostr(loaded_table->total);
	record = list_add_tail(record, id, strlen(id));
	tmp = tmp->next;
	while (tmp)
	{
		printf("Add %s: ", tmp->content);
		scanf("%s", cell_entry);
		record = list_add_tail(record, cell_entry, strlen(cell_entry));
		tmp = tmp->next;
	}
	return (record);
}

int		add_record(vector *loaded_table)
{
	t_list	*record_entry;

	record_entry = NULL;
	record_entry = store_input(loaded_table);
	vector_add_list(loaded_table, record_entry);
	return (1);
}
