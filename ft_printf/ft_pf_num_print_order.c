/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_print_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 19:40:49 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/04 19:40:51 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
void	ft_pf_num_prefix(t_mods *mod, t_pf_string *nbr, int *count)
{
	// printf("Entered\n");
	*count += ft_pf_num_sign(mod, nbr->neg, nbr->wpad, nbr->arg.mint);
	if (mod->hash)
	{
		if (mod->arg == 'x' || mod->arg == 'p')
			ft_putstr_fd("0x", 1);
		else if (mod->arg == 'X')
			ft_putstr_fd("0X", 1);
		*count += 2;
	}
}
int		ft_pf_num_pre_arg_print(t_mods *mod, t_pf_string *nbr)
{
	int 	count;

	count = 0;
	if (!(nbr->wpad && nbr->wpad[0] == ' '))
		ft_pf_num_prefix(mod, nbr, &count);
	if (!mod->left_align && nbr->wpad)
		ft_putstr_fd(nbr->wpad, 1);
	if (nbr->wpad && nbr->wpad[0] == ' ')
		ft_pf_num_prefix(mod, nbr, &count);
	
	if (nbr->neg == 1 && nbr->wpad && nbr->wpad[0] == ' ')
	{
		ft_putchar_fd('-', 1);
		// count++;
	}
	if (nbr->ppad)
		ft_putstr_fd(nbr->ppad, 1);
	return (count);
}



int		ft_pf_num_print_order(t_mods *mod, t_pf_string *nbr)
{
	int		count;
	int		index;

	count = 0;
	index = -1;
	count = ft_pf_num_pre_arg_print(mod, nbr);
	if ((nbr->len == 1 && nbr->num_str[0] == '0') && mod->p_active)
		return (count);
	while (nbr->num_str[++index] != '\0' && index < nbr->len)
		if (nbr->num_str[index] != '-')
			ft_putchar_fd(nbr->num_str[index], 1);
	if(mod->left_align && nbr->wpad)
	{
		if (mod->zero)
		{
			free(nbr->wpad);
			ft_strfill(nbr->wpad, ' ', mod->width);
		}
		ft_putstr_fd(nbr->wpad, 1);
	}
	return (count);
}

