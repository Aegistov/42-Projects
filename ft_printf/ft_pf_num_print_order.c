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
	*count += ft_pf_num_sign(mod, nbr->neg, nbr->wpad);
	if (mod->hash == x && !(mod->p_active && (nbr->len == 1 && nbr->num_str[0] == '0' && mod->arg != 'p')))
	{
		// if (mod->arg == 'o')
		// 	ft_putstr_fd("0", 1);
		if (mod->arg == 'x' || mod->arg == 'p')
			ft_putstr_fd("0x", 1);
		else if (mod->arg == 'X')
			ft_putstr_fd("0X", 1);
		*count += mod->hash;
	}
	if (mod->hash == 1)
	{
		ft_putstr_fd("0", 1);
		// printf("hash: %d\tcount: %d\n", mod->hash, *count);
		*count += mod->hash;
	}
	// *count += mod->hash;
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
	// printf("Count after pre: %d\n", count);
	// printf("nbr->len: %d\tnum_str[0]: %c\tmod->p_active: %d\n", nbr->len, nbr->num_str[0], mod->p_active);
	if ((nbr->len == 1 && nbr->num_str[0] == '0') && mod->p_active)
	{
		// printf("Nothing to print!\n");
		return (count);
	}
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
	// printf("Count: %d\n", count);
	return (count);
}

