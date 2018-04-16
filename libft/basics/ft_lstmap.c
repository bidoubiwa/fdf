/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:07:37 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/14 19:27:39 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*previous;
	t_list	*begin_list;

	begin_list = NULL;
	if (lst && f)
	{
		while (lst)
		{
			current = f(lst);
			current = ft_lstnew(current->content, current->content_size);
			if (begin_list)
				ft_lstaddafter(&previous, &current);
			else
				begin_list = current;
			previous = current;
			lst = lst->next;
		}
	}
	return (begin_list);
}
