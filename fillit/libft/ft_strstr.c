/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:42:31 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/05 12:42:32 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		bi;
	int		lil;

	bi = 0;
	lil = 0;
	if (!*little)
		return ((char *)big);
	while (big[bi])
	{
		lil = 0;
		while (big[bi + lil] == little[lil])
		{
			if (little[lil + 1] == '\0')
				return ((char *)&big[bi]);
			lil++;
		}
		bi++;
	}
	return (NULL);
}
