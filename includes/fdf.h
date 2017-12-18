/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:52:57 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 14:15:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1366
# define WIN_HEIGHT 768
# define ESC 53

typedef struct		s_pos
{
	double			x;
	double 			y;
}					t_pos;

typedef	struct		s_points
{
	double			x;
	double			y;
	double			z;
	t_pos			project;
}					t_points;

typedef struct		s_map
{
	t_points		**points;
	t_pos			min;
	t_pos 			max;
}					t_map;

typedef struct		s_env
{
	char			*path;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
	t_map			*map;
	int				width;
	int				height;
}					t_env;

int					expose_hook(void *param);
int					exit_hook(int keycode, void *param);
t_map				*read_file(char *path, t_env *env);
void				ft_error(int n);
int					init_win(t_env *env, int width, int height, char *name);
void				drawer(t_env *env);
void				projection_iso(t_map *map, t_env *env);
void				display_img(t_env *env);

#endif
