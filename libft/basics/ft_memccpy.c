/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:31:27 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 14:44:50 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*darray;
	unsigned char		*sarray;
	unsigned char		find;

	darray = (unsigned char *)dst;
	sarray = (unsigned char *)src;
	find = (unsigned char)c;
	while (n--)
	{
		*darray = *sarray;
		if (*sarray == find)
			return (++darray);
		sarray++;
		darray++;
	}
	return (NULL);
}
