/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:50:58 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/18 17:51:01 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchjoin(char const *s1, char c)
{
	char	*ptr;
	int		len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	ptr = NULL;
	if (!(ptr = (char *)malloc(len + 2)))
		return (NULL);
	ptr = ft_strcpy(ptr, s1);
	ptr[len] = c;
	ptr[len + 1] = '\0';
	return (ptr);
}
