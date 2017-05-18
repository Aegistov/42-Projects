/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:03:00 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 14:03:02 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		ini;
	int		ini2;

	if (!s1 || !s2)
		return (NULL);
	ini2 = 0;
	ptr = NULL;
	if (!(ptr = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ptr = ft_strcpy(ptr, (char*)s1);
	ini = ft_strlen(ptr);
	while (ini2 < ft_strlen(s2))
	{
		ptr[ini] = s2[ini2];
		ini++;
		ini2++;
	}
	ptr[ini] = '\0';
	return (ptr);
}
