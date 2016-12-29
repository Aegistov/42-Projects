/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:21:51 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 11:21:52 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	ini;

	ptr = NULL;
	ini = 0;
	if (!s)
	{
		return (NULL);
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (len + 1));
		if (ptr == NULL)
		{
			return (NULL);
		}
		while (ini < len)
		{
			ptr[ini] = s[start];
			ini++;
			start++;
		}
		ptr[ini] = '\0';
	}
	return (ptr);
}
