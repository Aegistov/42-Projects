/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:08:16 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/15 10:08:17 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	size = 0;
	if (!(tmp = (void *)ft_memalloc(sizeof(void) * size)))
		return (NULL);
	ft_memcpy(tmp, ptr, sizeof(ptr));
	// free(ptr);
	ptr = tmp;
	return (ptr);
}
