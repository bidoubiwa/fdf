/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:43:29 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 18:34:42 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clr(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	y;
	char			*new;
	char			*cnew;

	i = 0;
	y = 0;
	if (!s1 || !s2)
	{
		free(s2);
		free(s1);
		return (NULL);
	}
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	cnew = new;
	while (s1[i])
		*new++ = s1[i++];
	while (s2[y])
		*new++ = s2[y++];
	*new = '\0';
	free(s1);
	free(s2);
	return (cnew);
}
