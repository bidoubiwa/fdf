/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:35:34 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 18:05:49 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_point(t_point *points, int i, int res, t_line *matrix)
{
	if (res > matrix->max_z)
		matrix->max_z = res;
	if (res < matrix->min_z)
		matrix->min_z = res;
	points->z = (double) res;
	points->original_z = res;
	//points->x = (double) i;
	points->original_x = (double) i;
	//	points->y = (double)(matrix->height - 1);
	points->original_y = (double)(matrix->height - 1);
	points->original_w = 1;
	//points->w = 1;
}

int				add_points_to_line(t_point **points, char **row, t_line *matrix)
{
	int		i;
	long	res;
	int		valid;
	char	*hex;

	valid = 1;
	i = -1;
	while (++i < matrix->width)
	{
		if (!row[i])
			return(0);
		res = 0;
		points[i] = ft_memalloc(sizeof(t_point));
		hex = ft_atoi_only_numbers(row[i], &valid, &res);
		if (!valid)
			return (0);
		if (hex != NULL)
		{
			points[i]->color = ft_atoi_only_hex(hex, 16, &valid);
			if (!valid)
				return (0);
		}
		else
			points[i]->color = 0;
		fill_point(points[i], i, res, matrix);
	}
	free(row);
	return (1);
}

int				create_all_points_list(t_line *matrix, char **row)
{
	t_point		**points;
	t_point		***new;
	int			i;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_point**) * matrix->height)))
		return (0);
	if (!(matrix->points))
		matrix->points = new;
	else
	{
		while (i < matrix->height - 1)
		{
			new[i] = matrix->points[i];
			i++;
		}
		free(matrix->points);
		matrix->points = new;
	}
	if (!(points = ft_memalloc(sizeof(t_point*) * matrix->width)))
		return (0);
	matrix->points[i] = points;
	if (!(add_points_to_line(points, row, matrix)))
		return (0);
	return (1);
}

int				line_parsing(char *line, t_line *matrix)
{
	char	**row;

	if (!line)
		return (0);
	if (!(row = ft_strsplit(line, ' ')))
		return (0);
	if (matrix->width == -1)
		matrix->width = ft_strtablen(row);
	matrix->height = matrix->height + 1;
	if (!(create_all_points_list(matrix, row)))
		return (0);
	return (1);
}
