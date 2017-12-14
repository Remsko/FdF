/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:06:04 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:19:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_extremum(t_env *env,int x, int y)
{
	t_point	*proj;

	proj = &env->map[y][x].proj;
	if (!proj->x && !proj->y)
	{
		env->map[y][x].min.x = proj->x;
		env->map[y][x].min.y = proj->y;
		env->map[y][x].max.x = proj->x;
		env->map[y][x].max.y = proj->y;
	}
	else
	{
		env->map[y][x].min.x = proj->x < env->map[y][x].min.x ? proj->x : env->map[y][x].min.x;
		env->map[y][x].min.y = proj->y < env->map[y][x].min.y ? proj->y : env->map[y][x].min.y;
		env->map[y][x].max.x = proj->x > env->map[y][x].max.x ? proj->x : env->map[y][x].max.x;
		env->map[y][x].max.y = proj->y > env->map[y][x].max.y ? proj->y : env->map[y][x].max.y;
	}
}

void	projection_iso(t_env *env)
{
	int x;
	int y;
	t_point	*proj;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			proj = &env->map[y][x].proj;
			proj->x = (sqrt(2) / 2.0) * (env->map[y][x].x - env->map[y][x].y);
			proj->y = (sqrt(2 / 3.0) * env->map[y][x].z) - ((1.0 / sqrt(6)) * (env->map[y][x].x + env->map[y][x].y));
			get_extremum(env, x, y);
		}
	}
}
