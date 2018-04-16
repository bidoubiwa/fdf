/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:08:22 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/09 23:53:48 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		strlen;
	char	*origin;

	strlen = 0;
	while (str[strlen])
		strlen++;
	if (!(copy = (char *)malloc(sizeof(char) * (strlen + 1))))
		return (NULL);
	origin = copy;
	while (*str)
	{
		*copy++ = *str++;
	}
	*copy = '\0';
	return (origin);
}
