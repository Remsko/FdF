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

char		*read_file(int fd)
{
	char	*file;
	char	buf[BUFF_SIZE];
	int	ret;

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
