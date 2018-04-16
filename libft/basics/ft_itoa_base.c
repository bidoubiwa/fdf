/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:51:57 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 17:43:06 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(unsigned int v, int base)
{
	if (v == 0)
		return (0);
	else
		return (1 + ft_pow(v / base, base));
}

char		*ft_itoa_base(unsigned int value, unsigned int base)
{
	char			*res;
	unsigned int	p;
	int				i;

	i = ft_pow(value, base);
	p = value;
	if (value == 0)
		i = 1;
	if (!(res = ft_strnew(i)) || base < 2 || base > 16)
		return (NULL);
	while (--i >= 0)
	{
		res[i] = (p % base < 10) ? p % base + 48 : p % base - 10 + 'a';
		p = p / base;
	}
	return (res);
}
