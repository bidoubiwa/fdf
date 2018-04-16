/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chainfct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:43:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/20 22:14:08 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

void			ft_setup_chain_info(t_chain *elem, t_flag *flag)
{
	flag->left = 0;
	flag->blank = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->apos = 0;
	flag->hash = 0;
	elem->just_show = 0;
	elem->nbr_carac = 0;
	elem->error = 0;
	elem->width = 0;
	elem->give_p = 0;
	elem->prec = 0;
	elem->len = '\0';
	elem->maj = 0;
	elem->cnull = 1;
	elem->conv = 0;
	elem->show = NULL;
	elem->next = NULL;
}

void			ft_lstadd_after(t_chain *elem, t_chain **chain)
{
	t_chain	*tmp;

	tmp = *chain;
	if (tmp == NULL)
		*chain = elem;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
}

int				ft_show_only_parser(const char *format, size_t len, t_chain **c)
{
	char		*new;
	t_chain		*elem;

	if (!(new = ft_strsub(format, 0, len)))
		return (0);
	if (!(elem = ft_create_elem()))
		return (0);
	elem->just_show = 1;
	elem->nbr_carac = len;
	elem->show = new;
	ft_lstadd_after(elem, c);
	return (1);
}

t_chain			*ft_create_elem(void)
{
	t_chain	*new;
	t_flag	*flag;

	if (!(new = malloc(sizeof(t_chain))))
		return (NULL);
	if (!(flag = malloc(sizeof(t_flag))))
	{
		free(new);
		return (NULL);
	}
	new->flag = flag;
	ft_setup_chain_info(new, flag);
	return (new);
}
