/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:25:23 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/13 18:01:06 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*darray;
	unsigned char	*sarray;

	darray = dest;
	sarray = (void*)src;
	while (n--)
		*darray++ = *sarray++;
	return (dest);
}
