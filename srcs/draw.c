/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:22:36 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 14:55:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_env *env, t_points *points)
{
	int pts;
	int color;

	color = 0x00FFFFFF;
	pts = (floor(points->project.x) * env->bpp / 8) + (floor(points->project.y) * env->sline);
	env->data[pts++] = mlx_get_color_value(env->mlx, color);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 8);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 16);
	env->data[pts++] = mlx_get_color_value(env->mlx, color >> 20);
}

void	ft_normalize(t_points *points, t_env *env)
{
	t_pos *min;
	t_pos *max;

	min = &env->map->min;
	max = &env->map->max;
	points->project.x = ((points->project.x - min->x) / (max->x - min->x)) *
		(WIN_WIDTH - 1);
	points->project.y = ((points->project.y - min->y) / (max->y - min->y)) *
		(WIN_HEIGHT - 1);
}

void	draw_line(t_env *env, t_points *a, t_points *b)
{
	int i;
	int step;

	i = 0;
	(void)env;
	step = fabs(b->project.x - a->project.x) > fabs(b->project.y - a->project.y) ? fabs(b->project.x - a->project.x) : fabs(b->project.y - b->project.y);
	while (i++ < step)
	{
		a->project.x += (b->project.x - a->project.x) / (float)step;
		a->project.y += (b->project.y - a->project.y) / (float)step;
		put_pixel(env, a);
	}
}

void	drawer(t_env *env)
{
	int	x;
	int y;
	t_points **map;

	map = env->map->points;
	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			ft_normalize(&map[y][x], env);
			if (x > 0)
				draw_line(env, &map[y][x], &map[y][x - 1]);
			if (y < 0)
				draw_line(env, &map[y][x], &map[y - 1][x]);
			y++;
		}
		x++;
	}
}
