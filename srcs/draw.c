/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:22:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:32:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_env *env, t_map *map)
{
	int pts;
	int color;

	color = map->color ? map->color : 0x00FFFFFF;
	pts = (floor(map->proj.x) * env->bpp / 8) + (floor(map->proj.y) * env->sline);
	env->data[pts++] = mlx_get_color_value(env->mlx, color);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 8);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 16);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 20);
}

void	ft_normalize(t_env *env, int x, int y)
{
	t_point *min;
	t_point *max;

	min = &env->map[y][x].min;
	max = &env->map[y][x].max;
	env->map[y][x].proj.x = ((env->map[y][x].proj.x - min->x) / (max->x - min->x)) *
		(WIN_WIDTH - 1);
	env->map[y][x].proj.y = ((env->map[y][x].proj.y - min->y) / (max->y - min->y)) *
		(WIN_HEIGHT - 1);
}

void	draw_line(t_env *env, t_map *a, t_map *b)
{
	int i;
	int step;

	i = 0;
	step = fabs(b->proj.x - a->proj.x) > fabs(b->proj.y - a->proj.y) ? fabs(b->proj.x - a->proj.x) : fabs(b->proj.y - b->proj.y);
	while (i < step)
	{
		a->proj.x += (b->proj.x - a->proj.x) / (float)step;
		a->proj.y += (b->proj.y - a->proj.y) / (float)step;
		put_pixel(env, a);
	}
}

void	drawer(t_env *env)
{
	int	x;
	int y;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			ft_normalize(env, x, y);
			if (x > 0)
				draw_line(env, &env->map[y][x], &env->map[y][x - 1]);
			if (y < 0)
				draw_line(env, &env->map[y][x], &env->map[y - 1][x]);
		}
	}
}
