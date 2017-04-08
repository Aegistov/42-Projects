/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:08:43 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/01 19:08:45 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	*org;
	size_t			init;

	init = 0;
	c = (unsigned char)c;
	new = (unsigned char *)dest;
	org = (unsigned char *)src;
	while (init < n)
	{
		new[init] = org[init];
		if (org[init] == c)
		{
			return (&new[init + 1]);
		}
		init++;
	}
	return (NULL);
}
