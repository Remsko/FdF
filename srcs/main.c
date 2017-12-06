/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:07:30 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 15:58:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr("Usage : ./fdf <filename>\n");
	if (n == 2)
		ft_putstr("Error : failed to open file.\n");
	if (n == 3)
		ft_putstr("Error : failed to read file.\n");
	if (n == 4)
		ft_putstr("Error : malloc fail.\n");
	if (n == 5)
		ft_putstr("Error : get_next_line failed.\n");
	exit(EXIT_FAILURE);	
}

int			main(int ac, char **av)
{
	int		fd;
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)))
		{
			if (!(map = file_parse(fd)))
				ft_error(4);
		}
		else
			ft_error(2);
	}
	else
		ft_error(1);
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
