/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:57:49 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/09 23:51:10 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlap_in_memory(void *dst, const void *src, size_t len)
{
	while (len--)
	{
		if (src == dst)
			return (1);
		src++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (ft_overlap_in_memory(dst, src, len))
	{
		csrc += len;
		cdst += len;
		while (len--)
			*--cdst = *--csrc;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
