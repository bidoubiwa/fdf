/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisvalidint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:52:07 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/13 16:28:33 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (1);
}

int			ft_strisvalidint(const char *str)
{
	long			res;
	int				i;
	long			sign;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = is_neg(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (sign * (str[i++] - '0'));
		if (res > 2147483648)
			return (0);
		else if (res < -2147483647)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
