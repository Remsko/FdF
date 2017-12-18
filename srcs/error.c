/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:15:43 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 18:58:18 by rpinoit          ###   ########.fr       */
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
		ft_putstr("Error : invalid map.\n");
	if (n == 5)
		ft_putstr("Error : mlx_init failed.\n");
	if (n == 6)
		ft_putstr("Error : mlx_new_image failed.\n");
	if (n == 7)
		ft_putstr("Error : mlx_new_window failed.\n");
	if (n == 8)
		ft_putstr("Error : failed to malloc.\n");
	if (n == 9)
		ft_putstr("Error : failed to close file.\n");
	exit(EXIT_FAILURE);
}
