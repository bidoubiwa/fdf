/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:07:26 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/18 17:28:39 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int		ft_str_modifier(t_chain *elem, t_flag *flag)
{
	if (!elem->show)
		return (0);
	if (elem->give_p && elem->conv != 'c')
		elem->show = ft_precision(elem);
	if (elem->width > elem->nbr_carac)
		elem->show = ft_width(elem, flag);
	return (1);
}

int		ft_str_handler(t_chain *elem, va_list ap)
{
	char		c;

	if (elem->len == 'l')
		return (ft_str_w_handler(elem, ap));
	else if (elem->conv == 's')
	{
		if (!(elem->show = ft_strdupifexist(va_arg(ap, char *))))
			elem->show = ft_strdup("(null)");
		elem->nbr_carac = ft_strlen(elem->show);
	}
	else if (elem->conv == 'c')
	{
		c = va_arg(ap, int);
		if (c == '\0')
			elem->cnull = 0;
		elem->show = ft_strnew(elem->cnull);
		elem->show[0] = c;
		elem->nbr_carac = 1;
	}
	else
		elem->show = ft_strnew(0);
	return (ft_str_modifier(elem, elem->flag));
}
