/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:18:45 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:18:46 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_pf_str_init(t_pf_string *str)
{
	str->wpad = NULL;
	str->ppad = NULL;
	str->len = 0;
	str->neg = 0;
	str->wflag = 0;
	str->num_str = NULL;
}
