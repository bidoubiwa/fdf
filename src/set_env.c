/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:09:53 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/12 11:18:32 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			edit_matrix(t_line *matrix, t_env *env)
{
	int margex;
	int margey;

	printf("MAX_Z : %d Matrix W : %d Matrix H : %d\n",
			matrix->max_z, matrix->width, matrix->height);
	margex = env->win_width / 2 / 2;
	margey = env->win_height / 2 / 2;
	matrix->scale = fmin(env->win_width / 2 / (matrix->width + matrix->max_z),
			env->win_height / 2 / (matrix->height + matrix->max_z));
	matrix->scale = fmax(matrix->scale, 1);
	matrix->margin_x = env->win_width / 2;
	matrix->margin_y = env->win_height / 2;
}

static t_env		*init_env(int width, int height,
		char *filename, t_line *matrix)
{
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->win_height = height;
	env->win_width = width;
	env->data_addr = NULL;
	env->title = filename;
	env->matrix = matrix;
	env->bright = 0;
	env->color = 0;
	return (env);
}

t_env				*set_env(t_line *matrix, char *filename)
{
	t_env	*env;

	env = NULL;
	if (!(env = init_env(WIDTH_SCREEN, HEIGHT_SCREEN, filename, matrix)))
		return (NULL);
	edit_matrix(matrix, env);
	return (env);
}
