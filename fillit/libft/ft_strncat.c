/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:14:24 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 22:14:26 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		len;
	size_t		ini;

	ini = 0;
	len = ft_strlen(dest);
	while (src[ini] != '\0' && ini < n)
	{
		dest[len + ini] = src[ini];
		ini++;
	}
	dest[len + ini] = '\0';
	return (dest);
}
