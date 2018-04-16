/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:59:53 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/30 18:17:36 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *val, unsigned int from)
{
	unsigned int	res;
	int				i;
	unsigned int	exp;

	if (!val)
		return (0);
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
		else if (ft_tolower(val[i]) >= 91 && ft_tolower(val[i] <= 122))
		{
			res += ((ft_tolower(val[i]) - 97) + 10) * exp;
			exp = exp * from;
		}
	}
	return (res);
}
