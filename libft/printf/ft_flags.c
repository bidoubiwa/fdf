/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:48:13 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/17 18:57:17 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

char		*ft_plus(t_chain *elem, char c)
{
	char	*show;
	char	*new;
	size_t	len_src;

	show = elem->show;
	len_src = ft_strlen(show);
	if (ft_is_decimal(elem->conv) && ft_tolower(elem->conv) != 'u')
	{
		if (show[0] != '-')
		{
			if (!(new = ft_strnew(len_src + 1)))
				return (show);
			new[0] = c;
			new = ft_strncat(new, show, len_src);
			free(show);
			return (new);
		}
	}
	return (show);
}

char		*ft_maj(t_chain *elem)
{
	int		i;
	char	*show;

	show = elem->show;
	i = 0;
	if (ft_need_toupper(elem->conv))
	{
		while (show[i])
		{
			show[i] = ft_toupper(show[i]);
			i++;
		}
	}
	return (show);
}
