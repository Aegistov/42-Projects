/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:49:32 by mmorel            #+#    #+#             */
/*   Updated: 2016/10/31 10:49:37 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
