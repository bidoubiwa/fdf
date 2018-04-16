/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:24:33 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/09 23:48:03 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	ch;
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == ch)
			return (cstr + i);
		i++;
	}
	return (NULL);
}
