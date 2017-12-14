/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:48:32 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:06:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     expose_hook(void *param)
{
	t_env   *env;

	env = (t_env*)param;
	read_file(env->path, env);
	projection_iso(env);
	drawer(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int     exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
