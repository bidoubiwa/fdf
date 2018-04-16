/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:22:35 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 15:05:03 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *ch;

	ch = (unsigned char *)str;
	while (n--)
	{
		*ch = (unsigned char)c;
		ch++;
	}
	return (str);
}
