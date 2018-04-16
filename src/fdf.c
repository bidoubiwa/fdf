/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 11:21:32 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/12 12:00:49 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	init_matrix(t_line *matrix)
{
	matrix->width = -1;
	matrix->height = 0;
	matrix->points = NULL;
	matrix->rotation_x = ft_to_radians(0);
	matrix->rotation_y = ft_to_radians(0);
	matrix->rotation_z = ft_to_radians(0);
	matrix->scale = 0;
	matrix->max_z = 0;
	matrix->min_z = 0;
	matrix->min_real_z = 0;
	matrix->max_real_z = 0;
}
int				check_options(int ac, char **av, t_env *env)
{
	int nbr_options;
	int	i;

	nbr_options = ac - 2;

	i = 2;
	if (nbr_options)
	{
		while (i < ac)
		{
			if (ft_strequ(av[i], "-b"))
				env->bright = 1;
			else if (ft_strequ(av[i], "-c"))
				env->color = 1;
			else
				return (0);
			i++;
		}
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_line		matrix;
	t_env		*env;

	init_matrix(&matrix);
	if (!(ft_check_arguments(av[0], ac, 1, 3)))
		return (0);
	if (!(lines_to_struct(av[1], &matrix)))
		return (0);
	if (!(matrix.height > 0 && matrix.width > 0))
		return (0);
	if (!(env = set_env(&matrix, av[1])))
		return (0);
	if (!(check_options(ac, av, env)))
		return (0);
	transform_points(&matrix, env);
	init_mlx(env);
	fdf_handler(&matrix, env);
	return (0);
}
