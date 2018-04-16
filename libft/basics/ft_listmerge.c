/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listmerge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:39:37 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 16:42:10 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curseur;

	if (begin_list2 == 0)
		return ;
	if (*begin_list1 == 0 || begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	curseur = *begin_list1;
	while (curseur->next)
		curseur = curseur->next;
	curseur->next = begin_list2;
}
