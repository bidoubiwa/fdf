/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:22:28 by cvermand          #+#    #+#             */
/*   Updated: 2018/04/16 16:24:02 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int rgb_to_hex(int r, int g, int b)
{
	unsigned int hex;
	
	hex = (r << 16) + (g << 8) + b;
	return (hex);
}


unsigned int hsv_calculator(t_point *new,  t_line *matrix, int original_z, t_env *env)
{
	int		hue;
	double	saturation;
	double	bright;
	double	chroma;
	double	min;
	double  x;

	if (!env->color)
		saturation = 0;
	else 
		saturation = 0.79;
	if (original_z >= 0 && matrix->max_z != 0 && env->color)
		hue = (int)round(90.0 - ((((double)original_z / (double)matrix->max_z)) * 90.0));
	else if (original_z < 0 && matrix->min_z != 0 && env->color)
		hue = fmin((int)round(140.0 + (fabs(((double)original_z / (double)matrix->min_z)) * 140.0)), 255.0);
	else
		hue = 90;
	if (env->bright)	
		bright = fmax((fabs(new->z + fabs(matrix->min_real_z)) / matrix->total_real),0.25);
	else
		bright = 0.70;
	chroma = bright * saturation;
	min = bright - chroma;
	x = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
	if (hue >= 0 && hue <= 60)
		return (rgb_to_hex((int)round((chroma + min) * 255),(int)round((x + min) * 255),(int)round(min * 255)));
	if (hue > 60 && hue <= 120)
		return (rgb_to_hex((int)round((x + min) * 255),(int)round((chroma + min) * 255),(int)round(min * 255)));
	if (hue > 120 && hue <= 180)
		return (rgb_to_hex((int)round((min) * 255),(int)round((chroma + min) * 255),(int)round((x + min) * 255)));
	if (hue > 180 && hue <= 240)
		return (rgb_to_hex((int)round(min * 255),(int)round((x + min) * 255),(int)round((chroma + min) * 255)));
	else
		return (rgb_to_hex((int)round((x + min)* 255),(int)round((min) * 255),(int)round((chroma + min) * 255)));
	return (0);
}


unsigned int get_red_shade( t_env *env, t_point *new, int original_z)
{
	int		max_z;
	int		min_z;
	int		new_z;
//	int		g;
	
	max_z = (env->matrix)->max_z;
	new_z = max_z -  original_z;
	min_z = (env->matrix)->min_z;

	return (hsv_calculator(new, env->matrix, original_z, env));	
}

void		draw_point(t_point *new, t_env *env, t_point *p, int original_z)
{
	int				pos;
	unsigned int	hex;

//	if (x > (env->matrix)->max_z || x <  (env->matrix)->min_z)
//		printf("fake z : %.0d o-x : %f o-y : %f o-z : %f\n", x, p->original_x, p->original_z, p->original_z);
//	if (new->z > (env->matrix)->max_real_z || new->z <  (env->matrix)->min_real_z)
//		printf("new real z  : %.0f o-x : %.0f o-y : %.0f o-z : %.0f\n", new->z, p->original_x, p->original_z, p->original_z);

	

	//printf("z evolve : %d\n", x);
	if (p->color == 0)
		hex = get_red_shade(env, new, original_z);
	else
		hex = p->color;
	pos = nearbyint(nearbyint(new->y) * env->win_width + nearbyint(new->x));
	if (new->x >= 0 && new->x < 2560 && new->y < 1440 && new->y >= 0 
		&& pos >= 0 && pos < env->win_width * env->win_height)
	{
		if (env->data_addr[pos] <  mlx_get_color_value(env->mlx, hex))
		env->data_addr[pos] = mlx_get_color_value(env->mlx, hex);
//		printf("pos : %u\n", env->data_addr[pos]);
	}
}

int			get_diagonal_point(t_point *p1, t_point *p2, t_env *env)
{
	double	 difx;
	double	 dify;
	double  tan;
	
	difx = fabs(p1->x - p2->x);
	dify = fabs(p1->y - p2->y);
	tan = dify / difx;	
	if (p1->x < p2->x && p1->y < p2->y)
		north_east_line(p1, p2, env, tan);
	if (p1->x < p2->x && p1->y > p2->y)
		north_west_line(p1, p2, env, tan);
	if (p1->x > p2->x && p1->y < p2->y)
		south_east_line(p1, p2, env, tan);
	if (p1->x > p2->x && p1->y > p2->y)
		south_west_line(p1, p2, env, tan);
		//if (p1->x < p2->x)
	return (1);
}

int			draw_line_between_points(t_point *p1, t_point *p2, t_env *env)
{
	double		difx;
	double 		dify;
	double		newx;
	t_point 	tmp;
	int			sign;

	difx = fabs(p1->x - p2->x);
	dify = fabs(p1->y - p2->y);
	if (dify == 0)
	{
		while (difx)
		{
			sign = get_new_z(p1,p2,  difx, env);
			newx = (p1->x > p2->x) ? p1->x - difx : p1->x + difx;
			tmp.z = get_new_real_z(p1, p2, difx, env); 
			tmp.x = newx;
			tmp.y = p1->y;
			draw_point(&tmp, env, p1, sign);
			difx--;
		}
	}
	else if (difx == 0)
	{
		while (dify)
		{

			sign = get_new_z(p1,p2, dify, env);	
			newx = (p1->y > p2->y) ? p1->y - dify : p1->y + dify;
			tmp.z = get_new_real_z(p1, p2, dify, env); 
			tmp.x = p1->x;
			tmp.y = newx;
			draw_point(&tmp, env, p1,  sign);
			dify--;
		}
	}
	else 
		get_diagonal_point(p1, p2, env);
	return (1);
}

int			points_to_image(t_line *matrix, t_env *env)
{
	int		y;
	int		x;
	t_point		***points;
	
	points = matrix->points;
	matrix->total_real = fabs(matrix->max_real_z) + fabs(matrix->min_real_z);
	y = 0;
	while (y < matrix->height)
	{
		x = 0;
		while (x < matrix->width)
		{
//			printf("x : %f y : %f z : %f \n", points[y][x]->x, points[y][x]->y, points[y][x]->z)
			

			draw_point(points[y][x], env, points[y][x], points[y][x]->original_z);
		//	if (y == matrix->height / 2 && x == matrix->width / 2)
		//		draw_point(points[y][x], env, points[y][x], -1);
			if (x < matrix->width - 1)
				draw_line_between_points(points[y][x], points[y][x + 1], env);
			if (y < matrix->height - 1)
				draw_line_between_points(points[y][x], points[y + 1][x], env);
			x++;
		}
		//printf("\n");
		y++;
	}

//	draw_point(1280, 720,env, 0x00FEB1);
	return (1);
}

int			fdf_handler(t_line *matrix, t_env *env)
{
	points_to_image(matrix, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
//	mlx_string_put (env->mlx, env->win, 0, 0, 0x00ffffff, ft_itoa());
	events_listener(env);
	mlx_loop(env->mlx);
	return (1);
}
