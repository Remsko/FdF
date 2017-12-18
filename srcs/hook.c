/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:48:32 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 19:21:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    free_map(t_env *env)
{
	t_map   *tmp;
	int     i;

	i = 0;
	tmp = (t_map *)env->map;
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
	int		i;
	t_env	*env;
	t_map	*map;

	i = 0;
	env = (t_env*)param;
	map = read_file(env->path, env);
	env->map = map;
	projection_iso(map, env);
	drawer(env);
	display_img(env);
	if (!i)
	{
		free_map(env);
		ft_putstr("map is free");
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
