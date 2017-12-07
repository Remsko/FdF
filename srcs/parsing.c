/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:15:55 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/07 15:08:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include	<stdio.h>

t_map	get_map(char *file)
{
	t_mlx	*mlx;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	if (!(mlx = (t_mlx*)malloc(sizeof(t_point) * (mlx->size))))
			ft_error(8);
	while (*file)
	{
		mlx->map[i].x = x++;
		mlx->map[i].y = y;
		mlx->map[i].z = ft_atoi(file);
		if (*file && *file != ' ' && *file != '\0')
			++file;
		if (*file == '\n' && (++y))
			x = 0;
		while (*file && (*file == ' ' || *file != '\n'))
			++file;
		i++;
	}
	return (map);
}
