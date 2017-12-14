/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:14:35 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:27:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     init_win(t_env *env, int width, int height, char *name)
{
	if (!(env->mlx = mlx_init()))
		ft_error(5);
	if (!(env->img = mlx_new_image(env->mlx, width, height)))
		ft_error(6);
	if (!(env->win = mlx_new_window(env->mlx, width, height, name)))
		ft_error(7);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline, &env->endian);
	mlx_expose_hook(env->win, &expose_hook, &env);
	mlx_key_hook(env->win, &exit_hook, &env);
	return (1);
}
