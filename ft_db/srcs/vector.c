/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:05:41 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 13:32:19 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_db.h"

void		vector_init(vector *v)
{
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	v->items = malloc(sizeof(t_list *) * v->capacity);
}

void		vector_resize(vector *v, int capacity)
{
	void	**items;

	items = realloc(v->items, sizeof(void *) * capacity);
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}

void		vector_add_list(vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[v->total] = (t_list *)malloc(sizeof(t_list));
	v->items[v->total] = item;
	v->total++;
}

void		vector_set(vector *v, int index, void *item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void		vector_delete(vector *v, int index)
{
	int	i;

	i = index;
	if (index < 0 || index >= v->total)
		return ;
	v->items[index] = NULL;
	while (i < v->total - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		i++;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}
