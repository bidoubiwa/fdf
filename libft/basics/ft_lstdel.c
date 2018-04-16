/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:18:07 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 15:07:55 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	if (alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = ptr->next;
		}
		(*alst) = NULL;
	}
}
