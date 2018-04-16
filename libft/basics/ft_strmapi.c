/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:38:35 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 16:27:58 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				new[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (new);
}
