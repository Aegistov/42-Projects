/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ud_len_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:08:25 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 22:08:26 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pf_llu_len_base(unsigned long long n, const int base)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i);
	}
	else
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i + 1);
	}
}

int		ft_pf_hhu_len_base(unsigned char n, const int base)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i);
	}
	else
	{
		while (n != 0)
		{
			n /= base;
			i++;
		}
		return (i + 1);
	}
}

