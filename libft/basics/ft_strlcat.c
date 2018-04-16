/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:23:57 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 14:54:03 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	lendst;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (len <= lendst)
		return (lensrc + len);
	while (*dst && len-- > 1)
		dst++;
	while (*src && len-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (lensrc + lendst);
}
