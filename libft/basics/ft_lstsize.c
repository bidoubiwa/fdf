/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:50:52 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/15 20:38:56 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*buff;

	buff = begin_list;
	i = 0;
	if (begin_list)
	{
		while (buff != NULL)
		{
			i++;
			buff = buff->next;
		}
	}
	return (i);
}
