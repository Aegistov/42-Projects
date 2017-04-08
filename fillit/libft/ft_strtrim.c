/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:19:46 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/04 11:19:47 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	char	*new;

	if (!s)
		return (NULL);
	new = NULL;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (ft_strlen(s) == 0)
		new = ft_memalloc(0);
	else
	{
		end = ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		if (!(new = ft_strnew(end + 1)))
			return (NULL);
		while (end > -1)
		{
			new[end] = s[end];
			end--;
		}
	}
	new[ft_strlen(s)] = '\0';
	return (new);
}
