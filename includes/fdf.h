/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:52:57 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:19:17 by rpinoit          ###   ########.fr       */
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

typedef struct		s_point
{
	double x;
	double y;
}					t_point;

typedef struct		s_map
{
	double	x;
	double	y;
	double	z;
	int		color;
	t_point	proj;
	t_point	min;
	t_point max;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*path;
	int				bpp;
	int				sline;
	int				endian;
	t_map			**map;
	int				width;
	int				height;
}					t_env;

int					expose_hook(void *param);
int					exit_hook(int keycode, void *param);
t_env				*read_file(char *path, t_env *env);
void				ft_error(int n);
int					init_win(t_env *env, int width, int height, char *name);
void				drawer(t_env *env);
void				projection_iso(t_env *env);

#endif
