/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:20:48 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 16:00:31 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	del_record(vector *loaded_table)
{
	int	delete_line;

	printf("ID#: ");
	scanf("%d", &delete_line);
	vector_delete(loaded_table, delete_line);
	return (1);
}
