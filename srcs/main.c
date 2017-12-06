/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:07:30 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 18:37:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include	<stdio.h>

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr("Usage : ./fdf <filename>\n");
	if (n == 2)
		ft_putstr("Error : failed to open file.\n");
	if (n == 3)
		ft_putstr("Error : failed to read file.\n");
	if (n == 4)
		ft_putstr("Error : empty map.\n");
	if (n == 5)
		ft_putstr("Error : mlx_init failed.\n");
	if (n == 6)
		ft_putstr("Error : mlx_new_image failed.\n");
	if (n == 7)
		ft_putstr("Error : mlx_new_window failed.\n");
	exit(EXIT_FAILURE);	
}

int	init_win(t_mlx mlx, width, height, char *name)
{
	if ((mlx.mlx = mlx_init()) == NULL)
		ft_error(5);
	if ((mlx.img = mlx_new_image(mlx.mlx, width, height)) == NULL)
		ft_error(6);
	if ((mlx.win = mlx_new_window(mlx.mlx, width, height)) == NULL)
		ft_error(7);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sline, &mlx.endian);
	mlx_expose_hook(mlx.win, &expose_hook, &mlx);
	mlx_key_hook(mlx.win, &exit_hook, &mlx);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;
	char		*file;
	t_mlx		mlx;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)))
		{
			if (!(file = (read_file(fd))))
				return (0);
		}
		else
			ft_error(2);
	}
	else
		ft_error(1);
	if (!init_win(mlx, WIN_WIDTH, WIN_HEIGHT, av[1]);
	mlx_loop(mlx.mlx);
	return (0);
}
