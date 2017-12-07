/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:58:06 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/07 14:11:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"i

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
	if (!line)
		ft_error(4);
	return (file_map);
}

int		expose_hook(void *param)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	mlx = (t_mlx*)param;
	map = get_map(read_file((fd = open(mlx->path, RD_ONLY))));
	mlx->map = map;
}

int		exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(1);
	return (0);
}
