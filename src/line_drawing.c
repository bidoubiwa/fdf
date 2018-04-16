/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:56:52 by pfaust            #+#    #+#             */
/*   Updated: 2018/02/12 10:27:09 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int			get_new_real_z(t_point *p1, t_point *p2, int x, t_env *env)
{
	double		difx;
	double		difz;
	double		dify;
	t_env      *tmp;
	
	tmp = env;
	difz = fabs(p1->z - p2->z);
	difx = fabs(p1->x - p2->x);
	dify = fabs(p1->y - p2->y);

	if (p1->z == p2->z)
		return (p1->z);
	else if (p1->z < p2->z && difx != 0)
		return ((int)fmin(p1->z, p2->z) + (int)(ceil(difz * (double)x / difx)));
	else if (p1->z < p2->z && dify != 0)
		return ((int)fmin(p1->z, p2->z) + (int)(ceil(difz * (double)x / dify)));
	else if (p1->z > p2->z && difx != 0)
		return ((int)fmin(p1->z, p2->z) + (int)(difz + 1) - (int)(ceil(difz * (double)x / difx)));
	else if (p1->z > p2->z && dify != 0)
		return ( (int)fmin(p1->z, p2->z) + (int)(difz + 1) - (int)(ceil(difz * (double)x / dify)));
	return (0);
}

int			get_new_z(t_point *p1, t_point *p2, int x, t_env *env)
{
	double		difx;
	double		difz;
	double		dify;
	t_env      *tmp;
	
	tmp = env;
	difz = fabs(p1->original_z - p2->original_z);
	difx = fabs(p1->x - p2->x);
	dify = fabs(p1->y - p2->y);

	if (p1->original_z == p2->original_z)
		return (p1->original_z);
	else if (p1->original_z < p2->original_z && difx != 0)
		return ((int)fmin(p1->original_z, p2->original_z) + (int)(ceil(difz * (double)x / difx)));
	else if (p1->original_z < p2->original_z && dify != 0)
		return ((int)fmin(p1->original_z, p2->original_z) +  (int)(ceil(difz * (double)x / dify)));
	else if (p1->original_z > p2->original_z && difx != 0)
		return ((int)fmin(p1->original_z, p2->original_z) +  (int)(difz + 1) - (int)(ceil(difz * (double)x / difx)));
	else if (p1->original_z > p2->original_z && dify != 0)
		return ( (int)fmin(p1->original_z, p2->original_z) +  (int)(difz + 1) - (int)(ceil(difz * (double)x / dify)));
	return (0);
}

void		north_east_line(t_point *p1, t_point *p2, t_env *env, double tan)
{
	// Nord Ouest
	int			prev_y;
	double		new_y;
	int			x;
	t_point		tmp;
	int			sign;

	x = 1;
	prev_y = (int)p1->y;
	while (x + p1->x <= p2->x)
	{
		sign = get_new_z(p1, p2, x, env);
		tmp.z = get_new_real_z(p1, p2, x, env); 
		new_y = p1->y + (tan * (double)(x));
		while (nearbyint(++prev_y) < nearbyint(new_y))
		{
			tmp.x = x + p1->x;
			tmp.y = prev_y;
			draw_point(&tmp, env, p1, sign);
		}
		tmp.x = x + p1->x;
		tmp.y = prev_y;
		draw_point(&tmp, env,  p1, sign);
		prev_y = new_y;
		x++;
	}
}

void	north_west_line(t_point *p1, t_point *p2, t_env *env, double tan)
{
	// nord est
	int			prev_y;
	double		new_y;
	int			x;
	t_point		tmp;
	int			sign;

		x = 1;
	prev_y = p1->y;
	while (x + p1->x <= p2->x)
	{
		
		new_y = (p1->y - (tan * (double)(x)));
		sign = get_new_z(p1, p2, x, env);
		tmp.z = get_new_real_z(p1, p2, x, env); 
		while (--prev_y > new_y)
		{
			tmp.x = x + p1->x;
			tmp.y = prev_y;
			draw_point(&tmp, env,  p1, sign);
		}
		tmp.x = x + p1->x;
		tmp.y = prev_y;
		draw_point(&tmp, env,  p1, sign);
		prev_y = new_y;
		x++;
	}
}

void	south_east_line(t_point *p1, t_point *p2, t_env *env, double tan)
{
	// Sud ouest
	int			prev_y;
	double		new_y;
	int			x;
	t_point		tmp;
	int			sign;

	x = 1;
	prev_y = p1->y;
	while (p1->x - x >= p2->x)
	{
		new_y = (p1->y + (tan * (double)(x)));
		sign = get_new_z(p1, p2, x, env);
		tmp.z = get_new_real_z(p1, p2, x, env); 
		while (++prev_y < new_y)
		{
			tmp.x = p1->x - x;
			tmp.y = prev_y;
			draw_point(&tmp, env,  p1, sign);
		}
		tmp.x = p1->x - x;
		tmp.y = prev_y;
		draw_point (&tmp, env,  p1, sign);
		prev_y = new_y;
		x++;
	}
}

void	south_west_line(t_point *p1, t_point *p2, t_env *env, double tan)
{
	int			prev_y;
	double		new_y;
	int			x;
	t_point		tmp;
	int			sign;

	x = 1;
	prev_y = p1->y;
	while (p1->x - x >= p2->x)
	{	
		sign = get_new_z(p1, p2, x, env);
		tmp.z = get_new_real_z(p1, p2, x, env); 
		new_y = (p1->y - (tan * (double)(x)));
		while (--prev_y > new_y)
		{
			tmp.x = p1->x - x;
			tmp.y = prev_y;
			draw_point(&tmp, env, p1, sign);
		}
		tmp.x = p1->x - x;
		tmp.y = prev_y;
		draw_point(&tmp, env, p1, sign);
		prev_y = new_y;
		x++;
	}
}
