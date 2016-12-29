/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:43:42 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/02 15:43:44 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == 0 || *s2 == 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
