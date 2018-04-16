/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recognize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:51:07 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:46:01 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int		ft_need_toupper(char c)
{
	if (c == 'X' || c == 'E' || c == 'F' || c == 'G' || c == 'A')
		return (1);
	return (0);
}

int		ft_get_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'b')
		return (2);
	return (10);
}

char	*ft_start_digit(char *str, t_chain *elem)
{
	if (str[0] && str[1] && ft_tolower(elem->conv) != 'o')
	{
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			return (&str[2]);
		else if (str[0] == '-' || str[0] == '+' ||
				str[0] == '0' || str[0] == ' ')
			return (&str[1]);
	}
	return (str);
}

int		ft_is_integer(char b)
{
	if (ft_tolower(b) == 'd' || b == 'i' || ft_tolower(b) == 'o'
					|| ft_tolower(b) == 'u' || ft_tolower(b) == 'x' || b == 'p')
		return (1);
	return (0);
}

int		ft_is_decimal(char b)
{
	if (ft_tolower(b) == 'd' || b == 'i' || ft_tolower(b) == 'e' || b == 'u'
					|| ft_tolower(b) == 'f' || ft_tolower(b) == 'g')
		return (1);
	return (0);
}
