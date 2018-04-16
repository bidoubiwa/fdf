/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:21:13 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 16:27:08 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	new = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if ((new = ft_strnew(len)))
		{
			while (s[i])
			{
				new[i] = f(s[i]);
				i++;
			}
		}
	}
	return (new);
}
