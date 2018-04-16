/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:08:22 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/14 16:51:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strtabdup(char **tab)
{
	char	**copy_tab;
	size_t	tablen;
	size_t	i;

	if (!tab)
		return (NULL);
	i = 0;
	tablen = ft_strtablen(tab);
	if (!(copy_tab = ft_memalloc(sizeof(char *) * (tablen + 1))))
		return (NULL);
	while (i < tablen)
	{
		if (!(copy_tab[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	copy_tab[i] = NULL;
	return (copy_tab);
}
