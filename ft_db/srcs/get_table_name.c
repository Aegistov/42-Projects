/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_table_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:48:08 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 13:54:25 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*get_table_name(void)
{
	char	*table_name;
	char	*tmp;

	table_name = (char *)malloc(256);
	printf("Table Name: ");
	scanf("%s", table_name);
	tmp = (char *)malloc(strlen(table_name));
	tmp = strcpy(tmp, table_name);
	free(table_name);
	return (tmp);
}
