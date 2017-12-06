/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:15:55 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 15:58:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_count_line(int fd)
{
	int		ret;
	char	buf[32 + 1];
	int		count;
	int		i;

	count = 0;
	i = -1;
	while ((ret = read(fd, buf, 32)))
	{
		if (ret == -1)
			ft_error(3);
		buf[ret] = '\0';
		while (buf[++i])
		{
			if (buf[i] == '\n')
				count++;
		}
	}
	return (count);
}

char		**file_parse(int fd)
{
	char	**file_map;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	line = NULL;
	if (!(file_map = (char**)malloc(sizeof(ft_count_line(fd) + 1))))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
			ft_error(5);
		if (ret == 1)
		{
			file_map[i] = ft_strdup(*line);
			i++;
		}
	}
	ft_strdel(&line);
	file_map[i] = NULL;
	return (file_map);
}	
