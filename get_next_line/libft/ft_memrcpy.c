/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:41:01 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/08 11:45:47 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			end;

	end = n - 1;
	d = dest;
	s = (unsigned char*)src;
	while (n-- > 0)
	{
		d[end] = s[end];
		end--;
	}
	return (dest);
}
