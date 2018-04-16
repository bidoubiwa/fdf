/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 11:21:59 by cvermand          #+#    #+#             */
/*   Updated: 2018/02/12 11:18:51 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
//#include <stdlib.h>
# include <fcntl.h>
//#include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define WIDTH_SCREEN 2560
# define HEIGHT_SCREEN 1440

//#include "../minilibx_macos/mlx_new_window.h"

typedef struct		s_transform
{
	double				x[4];
	double				y[4];
	double				z[4];
	double				w[4];
}					t_transform;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			w;
	double			original_x;
	double			original_y;
	double			original_z;
	double			original_w;
	unsigned int	color;
}					t_point;

typedef struct		s_line
{
	int				width;
	int				height;
	double			scale;
	int				max_z;
	double			max_real_z;
	int				min_z;
	double			min_real_z;
	double			total_real;
	int				margin_x;
	int				margin_y;
	double			rotation_x;
	double			rotation_y;
	double			rotation_z;
	t_point			***points;
}					t_line;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*data_addr;
	char			*title;
	int				bits_per_pixel;
	int				bytes_per_line;
	int				endian;
	int				win_width;
	int				win_height;
	int				bright;
	int				color;
	t_line			*matrix;
}					t_env;
/*
 * SHOW FUNCTIONS 
 */
int		show_t_line(t_line *begin);
void	show_t_env(t_env *env);


/*
 * PARSING
 */
int					lines_to_struct(char *filename, t_line *matrix);
int					line_parsing(char *line, t_line *matrix);
t_env				*set_env(t_line *line, char *filename);
char				*ft_atoi_only_numbers(char *str, int *valid, long *res);
int					ft_atoi_only_hex(char *val, unsigned int from, int *valid);
void				transform_points(t_line *matrix, t_env *env);

/*
 * MLX
 */
void				init_mlx(t_env *env);

/*
 * HANDLING
 */
int					fdf_handler(t_line *matrix, t_env *env);
int					points_to_image(t_line *matrix, t_env *env);
void				rotate_x(t_line *matrix, t_transform *t);
void				rotate_y(t_line *matrix, t_transform *t);
void				rotate_z(t_line *matrix, t_transform *t);

/*
 * DRAWING
 */
void				draw_point(t_point *new, t_env *env, t_point *p, int x);
void				north_west_line(t_point *p1, t_point *p2, t_env *env, double tan);
void				north_east_line(t_point *p1, t_point *p2, t_env *env, double tan);
void				south_east_line(t_point *p1, t_point *p2, t_env *env, double tan);
void				south_west_line(t_point *p1, t_point *p2, t_env *env, double tan);
int					get_new_z(t_point *p1, t_point *p2, int x, t_env *env);
int					get_new_real_z(t_point *p1, t_point *p2, int x, t_env *env);
/*
 * EVENTS
 */
void				events_listener(t_env *env);
void				rotation(t_env *env, int keycode);
void				zoom(t_env *env, int keycode);
void				movement(t_env *env, int keycode);
void				show_rotations(t_env *env, t_line *matrix);
void				reset(t_env *env);
void				clear_image(t_env *env);

/*
 * FREEING
 */
void			free_all(t_env *env, t_line *matrix);
#endif
