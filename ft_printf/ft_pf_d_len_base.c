/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_d_len_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:30:49 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 22:30:50 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pf_lld_len_base(long long int n, const int base)
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

int		ft_pf_hhd_len_base(char n, const int base)
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

