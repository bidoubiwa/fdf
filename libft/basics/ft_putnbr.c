/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:06:28 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 15:04:14 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned x;

	if (n < 0)
		ft_putchar('-');
	x = ABS(n);
	if (n == 0)
		ft_putchar('0');
	else if (x > 0 && x < 10)
		ft_putchar(x + 48);
	else
	{
		ft_putnbr(x / 10);
		ft_putchar((x % 10) + 48);
	}
}
