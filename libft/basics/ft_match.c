/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:54:15 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 17:44:02 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_match(const char *s1, const char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 == *s2 && *s1 != '*')
		return (ft_match(s1 + 1, s2 + 1));
	else if (*s1 == '*' && *s2 == '*')
		return (ft_match(s1 + 1, s2));
	else if (*s2 == '*' && !*s1)
		return (ft_match(s1, s2 + 1));
	else if (*s2 == '*' && *s2 && *s1)
		return (ft_match(s1, s2 + 1) || ft_match(s1 + 1, s2));
	else
		return (0);
}
