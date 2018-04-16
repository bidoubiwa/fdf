/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:11:10 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 17:51:20 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		show_rotations(t_env *env, t_line *matrix)
{
	mlx_string_put(env->mlx, env->win, 50, 50, 0x00ffffff,
			"Rotation sur l'axe x (touches 8 et 2) : ");
	mlx_string_put(env->mlx, env->win, 450, 50, 0x00e60000,
			ft_itoa((int)ft_to_degrees(matrix->rotation_x) % 360));
	mlx_string_put(env->mlx, env->win, 50, 75, 0x00ffffff,
			"\nRotation sur l'axe y (touches 4 et 6) : ");
	mlx_string_put(env->mlx, env->win, 450, 75, 0x0033cc33,
			ft_itoa((int)ft_to_degrees(matrix->rotation_y) % 360));
	mlx_string_put(env->mlx, env->win, 50, 100, 0x00ffffff,
			"\nRotation sur l'axe z (touches 1 et 9) : ");
	mlx_string_put(env->mlx, env->win, 450, 100, 0x000099ff,
			ft_itoa((int)ft_to_degrees(matrix->rotation_z) % 360));
	mlx_string_put(env->mlx, env->win, 50, 125, 0x00ffffff,
			"\nEchelle (touches - et +) : ");
	mlx_string_put(env->mlx, env->win, 325, 125, 0x00ffcc00,
			ft_itoa((int)(matrix->scale)));
}

void		clear_image(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->win_width * env->win_height)
	{
		if (env->data_addr[i] != 0)
			env->data_addr[i] = 0;
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 83 || keycode == 84 || keycode == 86 ||
			keycode == 88 || keycode == 91 || keycode == 92)
		rotation(env, keycode);
	if (keycode == 78 || keycode == 69)
		zoom(env, keycode);
	if (keycode >= 123 && keycode <= 126)
		movement(env, keycode);
	if (keycode == 49)
		reset(env);
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		free_all(env, env->matrix);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void		events_listener(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
}
