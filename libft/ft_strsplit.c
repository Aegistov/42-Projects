/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:18:29 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/05 11:18:30 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		start_index(int i, char const *s, char c)
{
	while (s[i])
	{
		if (s[i] != c)
			return (i);
		i++;
	}
	return (i);
}

static	int		letter_count(int i, char const *str, char c)
{
	int		count;

	count = i;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i - count);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**nu;
	unsigned int		j;
	unsigned int		size;
	unsigned int		start;
	int					loader;

	if (!s)
		return (NULL);
	loader = 0;
	nu = NULL;
	start = 0;
	if (!(nu = (char **)malloc(sizeof(char *) * (ft_wdct(s, c) + 1))))
		return (NULL);
	while (loader < ft_wdct(s, c))
	{
		j = 0;
		start = start_index(start, s, c);
		size = letter_count(start, s, c);
		nu[loader] = ft_strsub(s, start, size);
		start += size;
		loader++;
	}
	nu[loader] = NULL;
	return (nu);
}
