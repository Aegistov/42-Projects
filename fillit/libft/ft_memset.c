/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:22:09 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/01 15:22:11 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			init;
	unsigned char	*test;

	init = 0;
	test = (unsigned char *)s;
	while (init < n)
	{
		test[init] = c;
		init++;
	}
	return (test);
}
