/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:32:01 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 14:21:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		if (!(init_win(&env, WIN_WIDTH, WIN_HEIGHT, av[1])))
			return (0);
	}
	else
		ft_error(1);
	mlx_loop(env.mlx);
	return (0);
}
