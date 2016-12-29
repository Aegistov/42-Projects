/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:55:58 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/11 21:55:59 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wdct(char const *str, char c)
{
	int		i;
	int		count;
	int		gate;

	i = 0;
	count = 0;
	gate = 0;
	while (str[i])
	{
		if (str[i] == c && gate == 1)
			gate = 0;
		if (str[i] != c && gate == 0)
		{
			gate = 1;
			count++;
		}
		i++;
	}
	return (count);
}
