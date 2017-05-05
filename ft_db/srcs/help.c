/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:55:59 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 15:57:02 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	help(void)
{
	printf("Welcome to the DBMS\n\n");
	printf("Looks like you need help, or maybe a friendly reminder!\n");
	printf("Enter a selection number.\n");
	printf("1 - Help Page\n");
	printf("2 - Load Table\n");
	printf("3 - Display Table\n");
	printf("4 - Add to Table\n");
	printf("5 - Delete from Table\n");
	printf("6 - Modify in Table\n");
	printf("7 - Save Table\n");
	printf("8 - Search Table\n");
	printf("0 - Exit Program\n");
}
