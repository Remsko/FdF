/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:10:08 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/07 16:12:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line.h"
# include "mlx.h"
#include <stdio.h>
# define WIN_WIDTH 2000
# define WIN_HEIGHT 2000
# define ESC 53

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*path;
	int			bpp;
	int			sline;
	int			endian;
	t_point		*map;
	int			size;
}				t_mlx;

t_mlx			*get_map(char *file, t_mlx *mlx);
int				exit_hook(int keycode, void *param);
int				expose_hook(void *param);
void			ft_error(int n);
char			*read_file(int fd);

#endif
