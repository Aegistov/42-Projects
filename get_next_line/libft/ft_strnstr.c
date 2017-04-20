/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:14:29 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/06 15:14:30 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		bi;
	size_t		lil;

	bi = 0;
	lil = 0;
	if (!*little)
		return ((char *)big);
	while (big[bi] && bi < len)
	{
		lil = 0;
		while (big[bi + lil] == little[lil] && (bi + lil) < len)
		{
			if (little[lil + 1] == '\0')
				return ((char *)&big[bi]);
			lil++;
		}
		bi++;
	}
	return (NULL);
}
