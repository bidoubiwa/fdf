/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:39:58 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/10 15:29:47 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int n;
	int turn;

	turn = 0;
	n = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[turn])
	{
		h = turn;
		while (haystack[h] == needle[n] && haystack[h] && needle[n])
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
