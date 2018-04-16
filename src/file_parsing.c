/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:50:30 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/12 12:01:01 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			lines_to_struct(char *filename, t_line *matrix)
{
	int		fd;
	char	*line;
	int		ret_gnl;
	
	if (((fd = ft_get_fd(filename)) < 0))
		return (0);
	while ((ret_gnl = get_next_line(fd, &line)) && ret_gnl > 0)
		if (!(line_parsing(line, matrix)))
			return (0);
	if (ret_gnl < 0)
		return (0);
	return (1);
}
