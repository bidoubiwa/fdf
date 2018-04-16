/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:30:54 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 15:02:57 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned x;

	if (n < 0)
		ft_putchar_fd('-', fd);
	x = ABS(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (x > 0 && x < 10)
		ft_putchar_fd(x + 48, fd);
	else
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd((x % 10) + 48, fd);
	}
}
