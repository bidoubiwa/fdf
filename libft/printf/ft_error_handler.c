/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:41:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 16:22:00 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

t_chain		*ft_lstfree(t_chain *current)
{
	t_chain *tmp;
	t_chain	*next;

	tmp = current;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->flag)
			free(tmp->flag);
		if (tmp->show)
			free(tmp->show);
		tmp->next = NULL;
		free(tmp);
		tmp = next;
	}
	return (NULL);
}

int			ft_percent_handler(t_chain *elem, va_list ap)
{
	(void)ap;
	if (!(elem->show = ft_strnew(1)))
		return (-1);
	elem->show[0] = '%';
	return (ft_str_modifier(elem, elem->flag));
}

static void	ft_w_error(t_chain *previous, t_chain *current, t_chain *elem)
{
	while (current)
	{
		if (current == elem || current->next == elem)
		{
			if (current->just_show == 1 || current == elem)
			{
				if (previous)
					previous->next = ft_lstfree(current);
				else
					current = ft_lstfree(current);
			}
			else
			{
				current->next = ft_lstfree(current->next);
			}
			break ;
		}
		if (current)
		{
			previous = current;
			current = current->next;
		}
	}
}

int			ft_show_error(t_chain *elem, t_chain *begin)
{
	t_chain		*current;
	t_chain		*previous;

	previous = NULL;
	if (ft_is_w_char(elem))
	{
		if (begin == elem)
			begin = ft_lstfree(begin);
		current = begin;
		ft_w_error(previous, current, elem);
		if (begin)
			ft_show_all(begin);
	}
	if (begin)
		ft_lstfree(begin);
	return (-1);
}

int			ft_error_handler(t_chain *elem, va_list ap)
{
	(void)ap;
	if (!(elem->show = ft_strnew(1)))
		return (-1);
	elem->show[0] = elem->conv;
	return (ft_str_modifier(elem, elem->flag));
}
