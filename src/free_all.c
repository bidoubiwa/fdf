/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:19:50 by pfaust            #+#    #+#             */
/*   Updated: 2018/02/08 16:48:36 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_matrix(t_line *matrix)
{
	int		y;
	int		x;

	y = 0;
	while (y < matrix->height)
	{
		x = 0;
		while (x < matrix->width)
		{
			free(matrix->points[y][x]);
			x++;
		}
		free(matrix->points[y]);
		y++;
	}
	free(matrix->points);
}

void		free_all(t_env *env, t_line *matrix)
{
	(void)env;
	free_matrix(matrix);
}
