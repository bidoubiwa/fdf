/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:07:33 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 15:02:14 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		len;
	int		pos;

	len = 0;
	pos = 0;
	while (dest[len] != '\0')
		len++;
	while (src[pos] != '\0')
	{
		dest[pos + len] = src[pos];
		pos++;
	}
	dest[pos + len] = '\0';
	return (dest);
}
