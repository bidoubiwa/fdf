/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:40:22 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/12 11:01:05 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_scale(double scale, t_transform *t, t_line *matrix)
{
//	scale = 15;
	(void) matrix;
	t->x[0] = scale;
	t->x[1] = 0;
	t->x[2] = 0;
	t->x[3] = 0;
//	t->y[0] = cos(env->rotation_x);
	t->y[0] = 0;
	t->y[1] = scale;
	t->y[2] = 0;
	t->y[3] = 0;
	t->z[0] = 0;
	t->z[1] = 0;
	t->z[2] = scale;
	t->z[3] = 1;
	t->w[0] = 0;
	t->w[1] = 0;
	t->w[2] = 0;
	t->w[3] = 1;
}

void			init_trans(int x_center, int y_center, t_transform *t)
{
//	printf("X trans : %d Y trans : %d\n", x, y);
	t->x[0] = 1;
	t->x[1] = 0;
	t->x[2] = 0;
	t->x[3] = x_center;

	//	t->y[0] = cos(env->rotation_x);
	t->y[0] = 0;
	t->y[1] = 1;
	t->y[2] = 0;
	t->y[3] = y_center;

	t->z[0] = 0;
	t->z[1] = 0;
	t->z[2] = 1;
	t->z[3] = 0;
	
	t->w[0] = 0;
	t->w[1] = 0;
	t->w[2] = 0;
	t->w[3] = 1;
}

void			matrix_multiplication(t_transform *t, t_point *point)
{
	double	x;
	double	y;
	double z;
	double w;
	
	x = (double)(point->x * t->x[0] + point->y * t->x[1] + point->z * t->x[2] + point->w * t->x[3]);
	y = (double)(point->x * t->y[0] + point->y * t->y[1] + point->z * t->y[2] + point->w * t->y[3]);
	z = (double)(point->x * t->z[0] + point->y * t->z[1] + point->z * t->z[2] + point->w * t->z[3]);
	w = (double)(point->x * t->w[0] + point->y * t->w[1] + point->z * t->w[2] + point->w * t->w[3]);
	//printf("x : %f y : %f z : %f w : %f\n", x, y, z, w);

	point->x = x;
	point->y = y;
	point->z = z;
	point->w = w;
}

static void		 	matrix_multiplication_plus(t_line *matrix, t_point *point, char c)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	if (c == 'x')
	{
		x = 1 * point->x;
		y = point->y * cos(matrix->rotation_x) - point->z * sin(matrix->rotation_x);
		z = point->y * sin(matrix->rotation_x) + point->z * cos(matrix->rotation_x);
	}
	else if (c == 'y')
	{
		x = point->x * cos(matrix->rotation_y) + point->z * sin(matrix->rotation_y);
		y = point->y;
		z = (1 - point->x * sin(matrix->rotation_y)) + point->z * cos(matrix->rotation_y);
	}
	else if (c == 'z')
	{
		x = point->x * cos(matrix->rotation_z) - point->y * sin(matrix->rotation_z);
		y = point->x * sin(matrix->rotation_z) + point->y * cos(matrix->rotation_z);
		z = point->z;
	}
	point->x = x;
	point->y = y;
	point->z = z;

}

void			transform_points(t_line *matrix, t_env *env)
{
	int			y;
	t_point		***points;
	t_transform	scale;
	t_transform	translation;
	int			x;
	t_env		*eenv;

	eenv = env;
	points = matrix->points;
	init_scale(matrix->scale, &scale, matrix);
	matrix->min_real_z = points[0][0]->z;
	//init_trans(matrix->margin_x, matrix->margin_y, &translation);	
	y = 0;
	while (y < matrix->height)
	{
		x = 0;
		while (x < matrix->width)
		{
			points[y][x]->x = points[y][x]->original_x;
			points[y][x]->y = points[y][x]->original_y;
			points[y][x]->z = points[y][x]->original_z;
			points[y][x]->w = points[y][x]->original_w;
			matrix_multiplication(&scale, points[y][x]);
			matrix_multiplication_plus(matrix, points[y][x], 'x');
			matrix_multiplication_plus(matrix, points[y][x], 'y');
			matrix_multiplication_plus(matrix, points[y][x], 'z');
		//	matrix_multiplication(&translation, points[y][x]);
			if (points[y][x]->z > matrix->max_real_z)
				matrix->max_real_z = points[y][x]->z;
			if (points[y][x]->z < matrix->min_real_z)
				matrix->min_real_z = points[y][x]->z;
			x++;
		}
		y++;
	}

	init_trans(
			matrix->margin_x - (int)points[matrix->height / 2][matrix->width / 2]->x, 
			matrix->margin_y - (int)points[matrix->height / 2][matrix->width / 2]->y, &translation);
	y = 0;
	while (y < matrix->height)
	{
		x = 0;
		while (x < matrix->width)
		{
			matrix_multiplication(&translation, points[y][x]);
			x++;
		}
		y++;
	}

}
