/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_of_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:41:27 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/31 09:27:46 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		hex_validity(char *val)
{
	int		i;

	i = 2;
	if (!(val[0] == '0' && ft_tolower(val[1]) == 'x'))
		return (0);
	while (ft_isdigit(val[i]) || (ft_tolower(val[i]) >= 97 &&
				ft_tolower(val[i]) <= 102))
		i++;
	if (val[i] != '\0')
		return (0);
	return (1);
}

int				ft_atoi_only_hex(char *val, unsigned int from, int *valid)
{
	unsigned int	res;
	int				i;
	unsigned int	exp;

	if (!val || !(*valid = hex_validity(val)))
		return (0);
	val = &val[2];
	exp = 1;
	i = ft_strlen(val);
	res = 0;
	while (--i >= 0)
	{
		if (ft_isdigit(val[i]))
		{
			res += (val[i] - '0') * exp;
			exp = exp * from;
		}
		else if (ft_tolower(val[i]) >= 97 && ft_tolower(val[i] <= 122))
		{
			res += ((ft_tolower(val[i]) - 97) + 10) * exp;
			exp = exp * from;
		}
	}
	return (res);
}

static int		is_neg(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (1);
}

char			*ft_atoi_only_numbers(char *str, int *valid, long *res)
{
	int				i;
	long			sign;

	i = 0;
	*valid = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = is_neg(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		*res = *res * 10 + (sign * (str[i++] - '0'));
		if (*res > 2147483648)
			return (0);
		else if (*res < -2147483647)
			return (0);
	}
	if (str[i] == '\0')
		return (NULL);
	if (str[i] == ',' && str[i + 1])
		return (&str[i + 1]);
	else
		*valid = 0;
	return (NULL);
}
