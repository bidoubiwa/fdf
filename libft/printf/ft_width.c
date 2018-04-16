/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:28:49 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/20 21:14:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static char		*ft_write_before_space(char *new, t_chain *elem)
{
	size_t i;
	size_t y;

	y = 0;
	i = 0;
	while (i < (elem->width - ft_strlen(elem->show)))
		new[i++] = ' ';
	while (i < elem->width)
		new[i++] = elem->show[y++];
	free(elem->show);
	return (new);
}

static char		*ft_write_before_zero(char *new, t_chain *elem)
{
	char *tmp;
	long i;
	long y;

	y = 0;
	i = 0;
	tmp = ft_start_digit(elem->show, elem);
	while (i < tmp - elem->show)
		new[i++] = elem->show[y++];
	while (i < (elem->width - ft_strlen(elem->show) + tmp - elem->show))
		new[i++] = '0';
	while ((size_t)i < elem->width)
		new[i++] = elem->show[y++];
	free(elem->show);
	return (new);
}

static char		*ft_write_after(char *new, t_chain *elem)
{
	size_t i;
	size_t y;

	y = 0;
	i = 0;
	while (i < (ft_strlen(elem->show)))
		new[i++] = elem->show[y++];
	while (i < elem->width)
		new[i++] = ' ';
	free(elem->show);
	return (new);
}

static char		*ft_width_w_char(t_chain *elem, t_flag *flag)
{
	size_t	len;
	char	*new;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	len = elem->width + ft_strlen(elem->show) - elem->nbr_carac;
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (!flag->left && i < (elem->width - elem->nbr_carac))
		new[i++] = ' ';
	while (elem->show[y])
		new[i++] = elem->show[y++];
	while (flag->left && i < len)
		new[i++] = ' ';
	elem->nbr_carac = elem->width;
	free(elem->show);
	return (new);
}

char			*ft_width(t_chain *elem, t_flag *flag)
{
	char	*new;

	if (ft_is_w_char(elem))
		return (ft_width_w_char(elem, flag));
	if (!(new = ft_strnew(elem->width)))
		return (elem->show);
	if (flag->left)
		return (ft_write_after(new, elem));
	else
	{
		if (flag->zero)
		{
			return (ft_write_before_zero(new, elem));
		}
		else
			return (ft_write_before_space(new, elem));
	}
	free(new);
	return (elem->show);
}
