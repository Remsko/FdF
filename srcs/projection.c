/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:06:04 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 15:29:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_extremum(t_map *map, t_points *proj)
{
	t_pos	*pos;

	pos = &proj->project;
	if (!proj->x && !proj->y)
	{
		map->min.x = pos->x;
		map->min.y = pos->y;
		map->max.x = pos->x;
		map->max.y = pos->y;
	}
	else
	{
		map->min.x = pos->x < map->min.x ? pos->x : map->min.x;
		map->min.y = pos->y < map->min.y ? pos->y : map->min.y;
		map->max.x = pos->x > map->max.x ? pos->x : map->max.x;
		map->max.y = pos->y > map->max.y ? pos->y : map->max.y;
	}
}

void	projection_iso(t_map *map, t_env *env)
{
	int			 x;
	int 		y;
	t_points	*proj;
	t_pos		*pos;

	x = 0;
	while (x < env->width)
	{
		y = 0;
		while (y < env->height)
		{
			proj = &map->points[y][x];
			pos = &proj->project;
			pos->x = (sqrt(2) / 2.0) * (proj->x - proj->y);
			pos->y = (-sqrt(2 / 3.0) * proj->z) - ((1.0 / sqrt(6)) * (proj->x + proj->y));
			get_extremum(map, proj);
			y++;
		}
		x++;
	}
}
