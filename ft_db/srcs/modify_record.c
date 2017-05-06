/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:50:49 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 14:07:16 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		modify_record(vector *loaded_table)
{
	int		id_number;
	t_list	*record_entry;
	char	*id;

	record_entry = NULL;
	printf("ID#: ");
	scanf("%d", &id_number);
	record_entry = store_input(loaded_table);
	id = itostr(id_number);
	record_entry->content = id;
	vector_set(loaded_table, id_number, record_entry);
	return (1);
}
