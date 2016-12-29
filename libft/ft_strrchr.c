/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:42:31 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/05 11:42:32 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ini;
	char	*tmp;

	tmp = (char *)s;
	ini = ft_strlen(s);
	while (ini >= 0)
	{
		if (tmp[ini] == c)
			return (&tmp[ini]);
		ini--;
	}
	return (NULL);
}
