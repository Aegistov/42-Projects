/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:36:09 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/08 11:10:32 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	len;
	size_t	copy;

	d = dst;
	s = (char*)src;
	copy = size;
	while (*d && copy-- > 0)
		d++;
	len = d - dst;
	copy = size - len;
	if (copy == 0)
		return (len + ft_strlen(src));
	while (*s)
	{
		if (copy > 1)
		{
			*d++ = *s;
			copy--;
		}
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
