/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:23:34 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 13:23:36 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		init;
	char	*ptr;

	init = 0;
	if (!s)
	{
		return (NULL);
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ptr == NULL)
		{
			return (NULL);
		}
		while (init < ft_strlen(s))
		{
			ptr[init] = f(init, s[init]);
			init++;
		}
		ptr[init] = '\0';
	}
	return (ptr);
}
