/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:01:33 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/30 13:40:39 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_found_newline(t_fd *current, char *buf,
		int ret, char **line)
{
	char *str_tmp;
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		if (!(*line = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(tmp))))
			return (-1);
		str_tmp = *line;
		if (!(*line = ft_strjoin(current->str, *line)))
			return (-1);
		ft_strdel(&str_tmp);
		str_tmp = current->str;
		if (!(current->str = ft_strsub(tmp, 1, ft_strlen(tmp) - 1)))
			return (-1);
		return (ft_strdel_n(&str_tmp) && ft_strdel_n(&buf));
	}
	else if (ret < BUFF_SIZE)
	{
		if (!(*line = ft_strjoin(current->str, buf)))
			return (-1);
		ft_strdel(&current->str);
		ft_strdel(&buf);
		return (1);
	}
	return (0);
}

static	int		ft_read(t_fd *current, int fd, char **line, int *r)
{
	char	*buf;
	int		ret;
	char	*tmp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((ret = ft_found_newline(current, buf, ret, line)) != 0)
			return (ret);
		tmp = current->str;
		if (!(current->str = ft_strjoin(current->str, buf)))
			return (-1);
		ft_strdel(&tmp);
	}
	if (ft_strlen(current->str) > 0)
	{
		if (!(*line = ft_strdup(current->str)))
			return (-1);
		ft_strdel(&current->str);
		ft_strdel(&buf);
		return (*r = 1);
	}
	return ((*line = current->str) ? 0 : -1);
}

static	int		ft_read_buff(t_fd *current, int fd, char **line)
{
	char	*origin;
	char	*tmp;
	int		ret;

	ret = 0;
	origin = current->str;
	if ((tmp = ft_strchr(origin, '\n')))
	{
		if (!(*line = ft_strsub(origin, 0, tmp - origin)))
			return (-1);
		if (!(current->str = ft_strsub(tmp, 1, ft_strlen(tmp) - 1)))
			return (-1);
		ft_strdel(&origin);
	}
	else
	{
		if ((ret = ft_read(current, fd, line, &ret)) < 0)
			return (-1);
		return (ret);
	}
	return (1);
}

static	int		ft_get_fd_struct(const int fd, t_fd **begin, t_fd **current)
{
	t_fd	*previous;
	t_fd	*tmp;

	previous = NULL;
	tmp = *begin;
	while (*current)
	{
		if ((*current)->fd == fd)
			return (1);
		previous = (*current);
		*current = (*current)->next;
	}
	if (!(*current = ft_memalloc(sizeof(t_fd))))
		return (-1);
	if (!((*current)->str = ft_strnew(0)))
		return (-1);
	(*current)->fd = fd;
	if (!previous)
		*begin = (*current);
	else
		previous->next = *current;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*list = NULL;
	t_fd			*current;
	int				state;
	char			*test[2];

	current = list;
	if (!line || fd < 0 || (ft_get_fd_struct(fd, &list, &current)) < 0
			|| (state = read(fd, test, 0)) == -1)
		return (-1);
	*line = NULL;
	if (!current->str)
	{
		if (!(current->str = ft_strnew(0)))
			return (-1);
	}
	state = ft_read_buff(current, fd, line);
	return (state);
}
