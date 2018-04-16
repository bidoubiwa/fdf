/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:30:25 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:45:26 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static int		ft_read_format(const char *restrict format, t_chain **chain)
{
	size_t		i;
	size_t		len;
	t_chain		*elem;

	elem = NULL;
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i != 0 && !(ft_show_only_parser(format, i, chain)))
				return (0);
			if (!(format = ft_parser(&format[++i], ft_create_elem(), chain)))
				return (0);
			i = 0;
		}
		else
			i++;
	}
	if (i != 0)
		if (!ft_show_only_parser(format, i, chain))
			return (0);
	return (1);
}

int				ft_printf(const char *restrict format, ...)
{
	t_chain		*chain;
	va_list		ap;

	va_start(ap, format);
	chain = NULL;
	if (!(ft_read_format(format, &chain)))
		return (-1);
	return (ft_handler(ap, chain));
}
