/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:52:28 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 16:52:17 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_line *matrix, t_transform *t)
{
	t->x[0] = 1;
	t->x[1] = 0;
	t->x[2] = 0;
	t->x[3] = 0;
	t->y[0] = 0;
	t->y[1] = cos(matrix->rotation_x);
	t->y[2] = (0 - sin(matrix->rotation_x));
	t->y[3] = 0;
	t->z[0] = 0;
	t->z[1] = sin(matrix->rotation_x);
	t->z[2] = cos(matrix->rotation_x);
	t->z[3] = 0;
	t->w[0] = 0;
	t->w[1] = 0;
	t->w[2] = 0;
	t->w[3] = 1;
}

void	rotate_y(t_line *matrix, t_transform *t)
{
	t->x[0] = cos(matrix->rotation_y);
	t->x[1] = 0;
	t->x[2] = sin(matrix->rotation_y);
	t->x[3] = 0;
	t->y[0] = 0;
	t->y[1] = 1;
	t->y[2] = 0;
	t->y[3] = 0;
	t->z[0] = 0 - sin(matrix->rotation_y);
	t->z[1] = 0;
	t->z[2] = cos(matrix->rotation_y);
	t->z[3] = 0;
	t->w[0] = 0;
	t->w[1] = 0;
	t->w[2] = 0;
	t->w[3] = 1;
}

void	rotate_z(t_line *matrix, t_transform *t)
{
	t->x[0] = cos(matrix->rotation_z);
	t->x[1] = 0 - sin(matrix->rotation_z);
	t->x[2] = 0;
	t->x[3] = 0;
	t->y[0] = sin(matrix->rotation_z);
	t->y[1] = cos(matrix->rotation_z);
	t->y[2] = 0;
	t->y[3] = 0;
	t->z[0] = 0;
	t->z[1] = 0;
	t->z[2] = 1;
	t->z[3] = 0;
	t->w[0] = 0;
	t->w[1] = 0;
	t->w[2] = 0;
	t->w[3] = 1;
}
