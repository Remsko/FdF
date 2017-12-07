/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:58:06 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/07 16:32:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char        *read_file(int fd)
{
	char    *file;
	char    buf[BUFF_SIZE];
	int     ret;

	file = NULL;
	if (fd == -1)
	{
		perror("fdf parsing error");
		return (NULL);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		file = ft_strjoin(file, buf);
	}
	if (ret == -1 || close(fd) == -1)
	{
		perror("fdf parsing error");
		return (NULL);
	}
	if (!file)
		ft_error(4);
	return (file);
}

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
