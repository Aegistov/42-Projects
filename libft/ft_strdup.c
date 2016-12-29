/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:01:11 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/02 12:01:14 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		size;
	int		init;
	char	*dest;

	init = 0;
	size = ft_strlen(s1) + 1;
	dest = NULL;
	dest = (char*)malloc(sizeof(*dest) * size);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (init < size)
	{
		dest[init] = s1[init];
		init++;
	}
	dest[init] = '\0';
	return (dest);
}
