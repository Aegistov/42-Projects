/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:35:06 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 13:35:30 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	display_loaded_table(vector *loaded_table)
{
	int	counter;

	counter = 0;
	while (counter <= loaded_table->total)
	{
		list_print(loaded_table->items[counter]);
		printf("\n");
		counter++;
	}
}
