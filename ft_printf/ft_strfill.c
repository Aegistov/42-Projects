/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:53:50 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/16 20:53:52 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

char	*ft_strfill(char *str, char c, int len)
{
	int		index;
	char	*tmp;

	index = 0;
	if (!(tmp = (char *)malloc(len + 1)))
		return (NULL);
	while (index < len)
	{
		tmp[index] = c;
		index++;
	}
	tmp[index] = '\0';
	if (str == NULL)
		str = tmp;
	else
		str = ft_strncpy(str, tmp, (size_t)len);
	return (str);
}
