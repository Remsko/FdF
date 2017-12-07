/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:58:06 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/07 16:47:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(void *param)
{
	t_mlx	*mlx;
	int		fd;

	mlx = (t_mlx*)param;
	get_map(read_file((fd = open(mlx->path, O_RDONLY))), mlx);
	return (0);
}

int		exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(1);
	return (0);
}
