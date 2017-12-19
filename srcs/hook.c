/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:48:32 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/19 18:02:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map *map, t_env *env)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (i < env->height)
	{
		free((void*)tmp->points[i]);
		i++;
	}
	free(tmp->points);
	free(tmp);
	tmp = NULL;
}

int		expose_hook(void *param)
{
	static int	i;
	t_env		*env;
	t_map		*map;

	env = (t_env*)param;
	map = read_file(env->path, env);
	env->map = map;
	projection_iso(map, env);
	drawer(env);
	display_img(env);
	if (i == 0)
	{
		free_map(map, env);
		i = 1;
	}
	return (0);
}

int		exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
