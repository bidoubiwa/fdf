/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:11:39 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/12 14:18:31 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*last;

	ch = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == ch)
			last = (char *)s;
		s++;
	}
	if (ch == '\0')
		last = (char *)s;
	return (last);
}
