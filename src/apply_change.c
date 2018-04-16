/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:14:46 by pfaust            #+#    #+#             */
/*   Updated: 2018/02/12 11:00:40 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		apply_rotation(t_env *env)
{
	transform_points(env->matrix, env);
	points_to_image(env->matrix, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	show_rotations(env, env->matrix);
}

void		rotation(t_env *env, int keycode)
{
	clear_image(env);
	env->matrix->min_real_z = 0;
	env->matrix->max_real_z = 0;
	if (keycode == 84)
		env->matrix->rotation_x = env->matrix->rotation_x + ft_to_radians(-10);
	if (keycode == 91)
		env->matrix->rotation_x = env->matrix->rotation_x + ft_to_radians(10);
	if (keycode == 86)
		env->matrix->rotation_y = env->matrix->rotation_y + ft_to_radians(-10);
	if (keycode == 88)
		env->matrix->rotation_y = env->matrix->rotation_y + ft_to_radians(10);
	if (keycode == 83)
		env->matrix->rotation_z = env->matrix->rotation_z + ft_to_radians(-10);
	if (keycode == 92)
		env->matrix->rotation_z = env->matrix->rotation_z + ft_to_radians(10);
	apply_rotation(env);
}

void		zoom(t_env *env, int keycode)
{
	clear_image(env);
	if (keycode == 78)
		env->matrix->scale = env->matrix->scale * 0.9;
	if (keycode == 69)
		env->matrix->scale = env->matrix->scale * 1.1;
	apply_rotation(env);
}

void		movement(t_env *env, int keycode)
{
	clear_image(env);
	if (keycode == 123)
		env->matrix->margin_x = env->matrix->margin_x - 50;
	if (keycode == 124)
		env->matrix->margin_x = env->matrix->margin_x + 50;
	if (keycode == 125)
		env->matrix->margin_y = env->matrix->margin_y + 50;
	if (keycode == 126)
		env->matrix->margin_y = env->matrix->margin_y - 50;
	apply_rotation(env);
}

void		reset(t_env *env)
{
	clear_image(env);
	env->matrix->margin_x = env->win_width / 2;
	env->matrix->margin_y = env->win_height / 2;
	env->matrix->scale = fmin(env->win_width / 2 / \
	(env->matrix->width + env->matrix->max_z), \
	env->win_height / 2 / (env->matrix->height + env->matrix->max_z));
	env->matrix->scale = fmax(env->matrix->scale, 1);
	env->matrix->rotation_x = ft_to_radians(30);
	env->matrix->rotation_y = ft_to_radians(30);
	env->matrix->rotation_z = (0);
	apply_rotation(env);
}
