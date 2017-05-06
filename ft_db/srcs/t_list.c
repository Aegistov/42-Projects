/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:06:15 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 13:53:35 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*load_list(t_list *list)
{
	char	*loaded_list;

	loaded_list = (char *)malloc(1000);
	bzero(loaded_list, 1000);
	while (list)
	{
		strcat(loaded_list, list->content);
		if (list->next)
		{
			loaded_list[strlen(loaded_list)] = ',';
			loaded_list[strlen(loaded_list)] = '\0';
		}
		else
		{
			loaded_list[strlen(loaded_list)] = '\n';
			loaded_list[strlen(loaded_list)] = '\0';
		}
		list = list->next;
	}
	return (loaded_list);
}

void	list_print(t_list *list)
{
	while (list)
	{
		if (list->next)
			printf("%15s\t", list->content);
		else
			printf("%15s", list->content);
		list = list->next;
	}
}

t_list	*list_init(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	if (!(list->content = (void*)malloc(content_size)))
		return (NULL);
	ft_memcpy(list->content, content, content_size);
	list->content_size = content_size;
	return (list);
}

int		list_search(t_list *list, char *str)
{
	while (list)
	{
		if (strstr(list->content, str))
			return (1);
		list = list->next;
	}
	return (0);
}

t_list	*list_add_tail(t_list *node, char *buf, size_t buf_size)
{
	t_list	*new;
	t_list	*tmp;

	new = list_init(buf, buf_size);
	if (node)
	{
		tmp = node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		node = new;
	return (node);
}
