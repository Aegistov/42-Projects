/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:59:06 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/03 09:59:08 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)ft_memalloc((size + 1))))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
