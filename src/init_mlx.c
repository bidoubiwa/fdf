/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:42:49 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 16:49:46 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_width,
			env->win_height, env->title);
	env->img = mlx_new_image(env->mlx, env->win_width, env->win_height);
	env->data_addr = (unsigned int*)mlx_get_data_addr(env->img,
			&env->bits_per_pixel, &env->bytes_per_line, &env->endian);
}
