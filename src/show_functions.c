/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:38:57 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/08 10:42:40 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		show_t_env(t_env *env)
{
	ft_printf("height : %-5d width : %-5d\n",env->win_height, env->win_width);
}

int		show_t_line(t_line *begin)
{
	t_point		***points;
	int		i;
	int		y;

	if(!begin || !begin->points)
		return (printf("BEGIN OU POINT EST NULL\n"));
	i = 0;
	points = begin->points;
	printf("Max width : %d height : %d scale : %f\n", begin->width, begin->height, begin->scale);
	while (i < begin->height)
	{
		y = 0;
		while (y < begin->width)
		{
			printf("%3f,%-3f,%-3f ", points[i][y]->x, points[i][y]->y, points[i][y]->z);
			y++;
		}
		printf("\n");
		i++;
	}
	return (1);
}
