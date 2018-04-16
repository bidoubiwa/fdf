/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupifexist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:29:05 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/17 18:18:00 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupifexist(const char *str)
{
	char	*copy;
	int		strlen;
	char	*origin;

	if (!str)
		return (NULL);
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
