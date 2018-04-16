/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_w_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:10:45 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 18:28:12 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int				ft_null_w_char(t_chain *elem)
{
	char	*byte;

	if ((elem->conv == 'C' || (elem->conv == 'c' && elem->len == 'l')))
	{
		byte = ft_strtrim(elem->show);
		if (ft_strequ(byte, "0"))
		{
			if (!(elem->flag)->left && elem->width > 0)
				write(1, elem->show, elem->width - 1);
			write(1, "\0", 1);
			if ((elem->flag)->left && elem->width > 0)
				write(1, elem->show, elem->width - 1);
			elem->nbr_carac = (elem->width > 0) ? elem->width : 1;
			free(byte);
			return (1);
		}
		free(byte);
		return (0);
	}
	return (0);
}

int				ft_is_w_char(t_chain *elem)
{
	if (elem->conv == 'c' && elem->len == 'l')
		return (1);
	else if (elem->conv == 's' && elem->len == 'l')
		return (1);
	else if (elem->conv == 'S' || elem->conv == 'C')
		return (1);
	return (0);
}

static char		*ft_w_char_handler(wchar_t wc, t_chain *elem)
{
	char			*bin;

	bin = NULL;
	if (!(wc <= 0x10ffff && wc >= 0 && (wc <= 0xd7ff || wc >= 0xe000)) &&
			(MB_CUR_MAX != 1 || ft_tolower(elem->conv) == 'c'))
		return (NULL);
	if (wc <= 127 && MB_CUR_MAX > 0)
		bin = ft_one_byte(wc);
	else if (wc > 127 && wc < 256 && MB_CUR_MAX == 1)
		bin = ft_itoa_base(wc, 2);
	else if (MB_CUR_MAX == 1 && ft_tolower(elem->conv) == 's')
	{
		if (elem->prec < (ft_strlen(elem->show) / 8) + 1 && elem->give_p)
			bin = ft_itoa_base(wc, 2);
	}
	else if (wc <= 2047 && MB_CUR_MAX > 1)
		bin = ft_two_bytes(wc);
	else if (wc <= 65535 && MB_CUR_MAX > 2)
		bin = ft_three_bytes(wc);
	else if (wc <= 1114111 && MB_CUR_MAX > 3)
		bin = ft_four_bytes(wc);
	if (bin)
		elem->nbr_carac += (ft_strlen(bin) / 8 == 0) ? 1 : ft_strlen(bin) / 8;
	return (bin);
}

static int		ft_str_big_s_handler(t_chain *elem, va_list ap)
{
	wchar_t		*sw;

	sw = va_arg(ap, wchar_t *);
	if (!sw)
	{
		elem->show = ft_strdup("(null)");
		elem->nbr_carac = ft_strlen(elem->show);
		elem->conv = 's';
		elem->len = 0;
	}
	else
	{
		elem->show = ft_strnew(0);
		while (*sw)
		{
			if (!(elem->show = ft_strjoin_clr(elem->show,
							ft_w_char_handler(*sw, elem))))
				return (-1);
			sw++;
		}
	}
	return (1);
}

int				ft_str_w_handler(t_chain *elem, va_list ap)
{
	int			res;

	if (elem->conv == 'C' || (elem->conv == 'c' && elem->len == 'l'))
	{
		if (!(elem->show = ft_w_char_handler(va_arg(ap, wchar_t), elem)))
			return (-1);
	}
	else if (elem->conv == 'S' || (elem->conv == 's' && elem->len == 'l'))
		if ((res = ft_str_big_s_handler(elem, ap)) == -1)
			return (-1);
	elem->nbr_byte = elem->nbr_carac;
	return (ft_str_modifier(elem, elem->flag));
}
