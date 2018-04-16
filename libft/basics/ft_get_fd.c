/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:18:51 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/29 11:29:02 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_fd(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("Error");
		return (fd);
	}
	return (fd);
}
