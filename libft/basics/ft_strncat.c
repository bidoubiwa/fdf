/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:45:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/09 17:54:56 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int		len;
	unsigned int		pos;

	len = 0;
	pos = 0;
	while (dest[len] != '\0')
		len++;
	while (pos < n && src[pos])
	{
		dest[pos + len] = src[pos];
		pos++;
	}
	dest[pos + len] = '\0';
	return (dest);
}
