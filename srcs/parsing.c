/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:15:55 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 18:39:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include	<stdio.h>

int	ft_count_line(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		cnt;
	int		i;

	cnt = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		if (ret == -1)
			ft_error(3);
		buf[ret] = '\0';
		while (buf[i])
		{
			if (buf[i] == '\n')
				cnt++;
			i++;
		}
	}
	close(fd);
	return (cnt);
}

char		**file_parse(int fd)
{
	char	**file_map;
	char	*line;
	int		ret;
	int		i;
	int		nb_line;

	i = 0;
	line = NULL;
	nb_line = ft_count_line(fd);
	if (!(file_map = (char**)malloc(sizeof(nb_line + 1))))
		return (NULL);
	while ((ret = get_next_line(fd = open(av[1], O_RDONLY), &line)) != 0)
	{
		ft_putnbr(1);
		if (ret == -1)
			ft_error(5);
		if (ret == 1)
			file_map[i++] = ft_strdup(line);
	}
	file_map[i] = NULL;
	i = 0;
	while (file_map[i])
	{
		printf("%s\n", file_map[i]);
		i++;
	}
	ft_putnbr(0);
	return (file_map);
}	
