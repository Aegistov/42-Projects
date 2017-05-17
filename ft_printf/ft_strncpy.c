/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:25:59 by mmorel            #+#    #+#             */
/*   Updated: 2016/10/31 11:26:01 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	len;

	len = 0;
	if (!*src)
	{
		ft_bzero(dest, n);
		return (dest);
	}
	while (n > 0 && src[len] != '\0')
	{
		dest[len] = src[len];
		n--;
		len++;
	}
	if (n > 0)
		ft_bzero(&dest[len], n);
	return (dest);
}
