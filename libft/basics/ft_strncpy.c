/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:00:47 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/10 00:45:29 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int index;

	index = 0;
	while (src[index] != '\0' && (index < len))
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
