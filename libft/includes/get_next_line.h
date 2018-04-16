/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:33:09 by cvermand          #+#    #+#             */
/*   Updated: 2018/01/03 21:48:16 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_fd
{
	int				fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);
#endif
