/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:03:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 14:50:46 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int h;
	unsigned int n;
	unsigned int turn;

	turn = 0;
	n = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[turn] && turn < len)
	{
		h = turn;
		while (haystack[h] == needle[n] && haystack[h] && needle[n] && h < len)
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack + turn);
			h++;
			n++;
		}
		n = 0;
		turn++;
	}
	return (NULL);
}
