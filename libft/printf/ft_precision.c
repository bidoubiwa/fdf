/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:28:03 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:44:09 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static int	ft_prec_null_str_null(t_chain *elem)
{
	if (ft_strequ(elem->show, "(null)") && elem->prec == '0')
	{
		free(elem->show);
		return (1);
	}
	return (0);
}

static char	*ft_prec_on_str(t_chain *elem)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (ft_prec_null_str_null(elem))
		return (ft_strnew(0));
	if (elem->prec < ft_strlen(elem->show))
	{
		i = 0;
		len = elem->prec;
		if (!(new = ft_strnew(len)))
			return (NULL);
		while (i < len)
		{
			new[i] = elem->show[i];
			i++;
		}
		elem->nbr_carac = ft_strlen(new);
		return (new);
	}
	return (elem->show);
}

static int	ft_prec_null_val_null(t_chain *elem, t_flag *flag)
{
	int	base;

	base = ft_get_base(elem->conv);
	if (elem->prec == 0 && elem->give_p == 1 &&
			elem->conv == 'p' && ft_atoi_base_ll(elem->show, base) == 0)
	{
		free(elem->show);
		elem->show = ft_strdup("0x");
		return (0);
	}
	else if (elem->prec == 0 && ft_is_decimal(elem->conv) && (flag->plus == 1
				|| flag->blank == 1) && ft_atoi_base_ll(elem->show, base) == 0)
	{
		free(elem->show);
		elem->show = (flag->plus) ? ft_strdup("+") : ft_strdup(" ");
		return (0);
	}
	else if (elem->prec == 0 && !((elem->flag)->hash && ft_tolower(elem->conv)
				== 'o') && ft_atoi_base_ll(elem->show, base) == 0)
	{
		free(elem->show);
		return (1);
	}
	return (0);
}

static char	*ft_prec_on_integer(t_chain *elem)
{
	char	*tmp;
	char	*new;
	long	i;
	long	y;

	i = 0;
	y = 0;
	(elem->flag)->zero = 0;
	if (ft_prec_null_val_null(elem, elem->flag))
		return (ft_strnew(0));
	tmp = ft_start_digit(elem->show, elem);
	if (elem->prec > ft_strlen(tmp))
	{
		if (!(new = ft_strnew(elem->prec + (tmp - elem->show))))
			return (elem->show);
		while (i < (tmp - elem->show))
			new[i++] = elem->show[y++];
		while ((UIL)i < elem->prec - ft_strlen(tmp) + (tmp - elem->show))
			new[i++] = '0';
		while ((UIL)i < elem->prec + (tmp - elem->show))
			new[i++] = elem->show[y++];
		free(elem->show);
		return (new);
	}
	return (elem->show);
}

char		*ft_precision(t_chain *elem)
{
	if (ft_is_integer(elem->conv))
		return (ft_prec_on_integer(elem));
	else if (elem->conv == 's' && elem->len != 'l')
		return (ft_prec_on_str(elem));
	else if (elem->conv == 'S' || (elem->len == 'l' && elem->conv == 's'))
		return (ft_prec_on_w(elem));
	return (elem->show);
}
