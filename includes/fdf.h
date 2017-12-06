/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:10:08 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/06 16:39:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line.h"
# include "mlx.h"
# define WIN_WIDTH 2000
# define WIN_HEIGHT 2000

typedef struct	s_mlx;
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int	bpp;
	int	sline;
	int	endian;
	
}		t_mlx;

void	ft_error(int n);
char	*read_file(int fd);

#endif
