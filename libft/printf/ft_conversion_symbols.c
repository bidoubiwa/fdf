/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_symbols.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:45:57 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:13:34 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

char		*ft_0x_hexa(char *show, char c, t_chain *elem)
{
	int		y;
	int		i;
	char	*new;
	int		res;

	res = ft_atoi_base_ll(show, 16);
	i = 0;
	y = 0;
	if (res == 0 && (ft_tolower(c) == 'x' || (c == 'p' && elem->give_p &&
					!elem->prec)))
		return (show);
	if (!(new = ft_strnew(ft_strlen(show) + 2)))
		return (NULL);
	new[i++] = '0';
	new[i++] = 'x';
	while (show[y])
		new[i++] = show[y++];
	free(show);
	return (new);
}

char		*ft_0_octal(char *show)
{
	char	*new;
	int		y;
	int		i;

	i = 0;
	y = 0;
	if (ft_atoi_base_ll(show, 8) == 0)
		return (show);
	if (!(new = ft_strnew(ft_strlen(show) + 1)))
		return (NULL);
	new[i++] = '0';
	while (show[y])
		new[i++] = show[y++];
	free(show);
	return (new);
}

char		*ft_hash(t_chain *elem)
{
	char	c;

	c = elem->conv;
	if (ft_tolower(c) == 'x' || elem->conv == 'p')
		return (ft_0x_hexa(elem->show, elem->conv, elem));
	else if (ft_tolower(c) == 'o')
		return (ft_0_octal(elem->show));
	return (elem->show);
}
