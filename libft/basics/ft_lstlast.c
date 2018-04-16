/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:47:08 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 16:49:01 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list	*buff;

	if (begin_list == 0)
		return (0);
	buff = begin_list;
	while (buff->next)
	{
		buff = buff->next;
	}
	return (buff);
}
