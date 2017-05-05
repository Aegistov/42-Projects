/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:17:43 by yolabi            #+#    #+#             */
/*   Updated: 2017/05/05 15:47:15 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	create_table(void)
{
	char	*table_name;
	char	*tmp;
	FILE	*table_file;

	table_name = get_table_name();
	table_file = fopen(table_name, "w+");
	tmp = (char *)malloc(256);
	bzero(tmp, 256);
	while (tmp[0] != '@')
	{
		bzero(tmp, 256);
		printf("Please input a field name input '@' before the final field: ");
		scanf("%s,", tmp);
		fprintf(table_file, "%s", tmp);
	}
	bzero(tmp, 256);
	scanf("%s", tmp);
	fprintf(table_file, "%s", tmp);
	free(tmp);
	free(table_name);
	fclose(table_file);
	return (1);
}
