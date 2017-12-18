/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:48:32 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 14:21:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     expose_hook(void *param)
{
	t_env   *env;
	t_map	*map;

	env = (t_env*)param;
	map = read_file(env->path, env);
	env->map = map;
	projection_iso(map, env);
	drawer(env);
	display_img(env);
	return (0);
}

int     exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
