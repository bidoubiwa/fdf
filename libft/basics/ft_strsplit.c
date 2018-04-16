/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:23:38 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 14:49:54 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbr_word(char const *s, char c)
{
	int		nbr;
	char	before;

	nbr = 0;
	before = c;
	while (*s)
	{
		if (*s && *s != c && before == c)
			nbr++;
		before = *s;
		s++;
	}
	return (nbr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	char	**words;
	int		start;
	int		end;

	word = 0;
	if (!s || !(words = (char **)malloc(sizeof(char *) * (nbr_word(s, c) + 1))))
		return (NULL);
	start = 0;
	while (s[start])
	{
		if (s[start] != c && s[start] != '\0')
		{
			end = start;
			while (s[end] != c && s[end])
				end++;
			if (!(words[word++] = ft_strsub(s, start, end - start)))
				return (NULL);
			start = end - 1;
		}
		start++;
	}
	words[word] = 0;
	return (words);
}
