/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:09:11 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 18:45:58 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

const char	*ft_parser(const char *format, t_chain *elem, t_chain **chain)
{
	const char	*tmp;
	int			y;

	if (!elem)
		return (NULL);
	y = 0;
	while (format && !elem->conv)
	{
		if (ft_find_flag(*format, elem))
			format++;
		else if (ft_isdigit(*format) && *format != '0')
			format = ft_find_width(&format[y], elem);
		else if (*format == '.')
			format = &format[(ft_find_precision(format, elem) - format)];
		else if ((tmp = ft_find_length(format, elem)))
			format = &format[tmp - format];
		else if (ft_is_conv(*format, elem))
		{
			ft_lstadd_after(elem, chain);
			return (++format);
		}
		else
			break ;
	}
	return (format);
}
