/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:45:36 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/28 11:13:53 by cvermand         ###   ########.fr       */
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

int			ft_atoi(const char *str)
{
	long double		res;
	int				i;
	long int		sign;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = is_neg(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))\
	{
		res = res * 10 + (sign * (str[i++] - '0'));
		if (res >= 9223372036854775807)
			return (-1);
		else if (res < -9223372036854775807)
			return (0);
	}
	while (res > 2147483647)
		res = res - 4294967296;
	while (res < -2147483648)
		res = res + 4294967296;
	return ((int)res);
}
