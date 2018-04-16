/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_w_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:57:42 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:26:53 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static int	ft_number_byte_for_carac(char *show, int y)
{
	int byte;

	byte = 0;
	while (show[y++] == '1')
		byte++;
	return (byte);
}

static void	ft_initialize_prec_on_w(t_chain *elem, size_t i)
{
	char	*tmp;

	tmp = elem->show;
	elem->show = ft_strsub(elem->show, 0, i * 8);
	elem->nbr_carac = i;
	elem->nbr_byte = i;
	free(tmp);
}

char		*ft_prec_on_w(t_chain *elem)
{
	size_t	i;
	int		carac;
	int		byte;

	i = 0;
	carac = 0;
	if (elem->prec > elem->nbr_byte)
		return (elem->show);
	while (i < elem->prec && elem->show[carac])
	{
		byte = 0;
		if (elem->show[carac] == '0' || MB_CUR_MAX == 1)
			byte++;
		else if (elem->show[carac] == '1')
			byte = ft_number_byte_for_carac(elem->show, carac);
		i += byte;
		carac = i * 8;
	}
	if (i > elem->prec)
		i -= byte;
	ft_initialize_prec_on_w(elem, i);
	return (elem->show);
}
