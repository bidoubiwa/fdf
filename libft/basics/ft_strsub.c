/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:25:08 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 14:51:50 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*c;

	if (!s || !(c = ft_strnew(len)))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(c, s, len);
	c[len] = '\0';
	return (c);
}
