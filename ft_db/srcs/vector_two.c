/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:45:15 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 16:45:18 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_db.h"

int			vector_total(vector *v)
{
	return (v->total);
}

void		*vector_get(vector *v, int index)
{
	if (index >= 0 && index < v->total)
	{
		list_print(v->items[index]);
		return (v->items[index]);
	}
	return (NULL);
}

void		vector_free(vector *v)
{
	int		counter;

	counter = 0;
	while (counter <= v->total)
	{
		free(v->items[counter]);
		counter++;
	}
}
