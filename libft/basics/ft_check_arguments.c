/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:42:36 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 17:43:36 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		print_error_message(char *exec)
{
	ft_putstr("Usage : ");
	ft_putstr(exec);
	ft_putendl(" <filename>");
	return (0);
}

int				ft_check_arguments(char *exec, int ac, int min, int max)
{
	if (ac - 1 < min)
		return (print_error_message(exec));
	else if (max != 0 && ac - 1 > max)
		return (print_error_message(exec));
	return (1);
}
