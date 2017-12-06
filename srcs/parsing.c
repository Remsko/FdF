/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:15:55 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 17:11:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include	<stdio.h>

int	ft_count_line(int fd)
{
	int		ret;
	char	buf[32 + 1];
	int		count;
	int		i;

	count = 0;
	i = 0;
	printf("%s\n", "test");
	while ((ret = read(fd, buf, 32)))
	{
		if (ret == -1)
			ft_error(3);
		buf[ret] = '\0';
		while (i < 32)
		{
			if (buf[i] == '\n')
				count++;
			i++;
		}
	}
	printf("count = %d\n", count);
	return (count);
}

char		**file_parse(int fd)
{
	char	**file_map;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if (!(file_map = (char**)malloc(sizeof(ft_count_line(fd) + 1))))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		printf("line = %s\n", line);
		if (ret == -1)
			ft_error(5);
		if (ret == 1 && !line)
			file_map[i++] = ft_strdup(line);
	}
	file_map[i] = NULL;
	i = 0;
	while (file_map != NULL)
	{
		printf("map = %s\n", file_map[i]);
		i++;
	}
	return (file_map);
}	
