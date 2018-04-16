/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:04:56 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/13 23:16:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddafter(t_list **alst, t_list **new)
{
	t_list	*tmp;

	if (alst)
	{
		tmp = (*alst)->next;
		if (new)
		{
			(*alst)->next = *new;
			(*new)->next = tmp;
		}
		else
			(*alst)->next = NULL;
	}
	else
		(*alst) = (*new);
}
