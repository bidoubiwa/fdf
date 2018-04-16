/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:47:31 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/11 20:55:37 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static int		ft_int_modifier(t_chain *elem)
{
	t_flag	*flag;

	flag = elem->flag;
	if (flag->plus)
		elem->show = ft_plus(elem, '+');
	if (!flag->plus && flag->blank)
		elem->show = ft_plus(elem, ' ');
	if (flag->hash || elem->conv == 'p')
		elem->show = ft_hash(elem);
	if (elem->maj)
		elem->show = ft_maj(elem);
	if (elem->give_p)
		elem->show = ft_precision(elem);
	if (elem->width > ft_strlen(elem->show))
		elem->show = ft_width(elem, flag);
	return (1);
}

int				ft_int_handler(t_chain *elem, va_list ap)
{
	char	*new;

	new = NULL;
	if ((!elem->len || elem->len == 'L') && elem->conv != 'D')
		new = ft_itoa(va_arg(ap, int));
	else if (elem->len == 'h' && elem->conv != 'D')
		new = ft_itoa_ll((short)va_arg(ap, int));
	else if (elem->len == 'H' && elem->conv != 'D')
		new = ft_itoa((char)va_arg(ap, int));
	else if (elem->len == 'l' || elem->conv == 'D')
		new = ft_itoa_ll(va_arg(ap, long));
	else if (elem->len == 'm')
		new = ft_itoa_ll(va_arg(ap, long long));
	else if (elem->len == 'j')
		new = ft_itoa_ll(va_arg(ap, intmax_t));
	else if (elem->len == 'z')
		new = ft_itoa_ll(va_arg(ap, ssize_t));
	if (new)
		elem->show = new;
	else
		elem->show = ft_strnew(0);
	return (ft_int_modifier(elem));
}

static int		ft_exception_uint(char c)
{
	if (c == 'U' || c == 'O' || c == 'p')
		return (1);
	return (0);
}

int				ft_uint_handler(t_chain *elem, va_list ap)
{
	char		*new;
	int			base;

	new = NULL;
	base = ft_get_base(elem->conv);
	if (elem->len == 'h' && !ft_exception_uint(elem->conv))
		new = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), base);
	else if (elem->len == 'H' && !ft_exception_uint(elem->conv))
		new = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), base);
	else if (elem->len == 'l' || ft_exception_uint(elem->conv))
		new = ft_itoa_base_ll(va_arg(ap, unsigned long), base);
	else if (elem->len == 'm')
		new = ft_itoa_base_ll(va_arg(ap, unsigned long long), base);
	else if (elem->len == 'j')
		new = ft_itoa_base_ll(va_arg(ap, uintmax_t), base);
	else if (elem->len == 'z')
		new = ft_itoa_base_ll(va_arg(ap, size_t), base);
	else
		new = ft_itoa_base(va_arg(ap, unsigned int), base);
	if (new)
		elem->show = new;
	else
		elem->show = ft_strnew(0);
	return (ft_int_modifier(elem));
}
