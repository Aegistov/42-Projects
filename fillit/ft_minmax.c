/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:30:47 by mmorel            #+#    #+#             */
/*   Updated: 2016/12/01 23:30:50 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_minmax(int s[], int op)
{
	int		holder;
	int		i;

	i = 0;
	holder = s[0];
	// printf("holder-pre: %d\n", holder);
	if (op == 0)
	{
		while (i < 4)
		{
			if (s[i] < holder)
				holder = s[i];
			i++;
		}
		// printf("holder-post: %d\n", holder);
		return (holder);
	}
	else if (op == 1)
	{
		while (i < 4)
		{
			if (s[i] > holder)
				holder = s[i];
		}
		return (holder);
	}
	return (holder);
}
