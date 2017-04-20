/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:01:12 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 22:01:13 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		len;
	int		src_len;
	int		total;

	len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total = len + src_len;
	while (len < total)
	{
		dest[len] = *src;
		len++;
		src++;
	}
	dest[len] = '\0';
	return (dest);
}
