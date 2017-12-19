/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:45:05 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/19 17:45:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		init_color(double pos, double y, double x)
{
	int			color;

	(void)y;
	(void)x;
	if (pos >= -100 && pos < -50)
		color = 0xFF9999;
	if (pos >= -50 && pos <= -1)
		color = 0xFFFF99;
	if (pos == 0)
		color = 0xFFCCFF;
	if (pos > 0 && pos <= 50)
		color = 0x99CCFF;
	if (pos >= 51 && pos <= 100)
		color = 0xFF99FF;
	if (pos > 100 && pos < 500)
		color = 0x9999FF;
	if (pos > 500)
		color = 0xE0E0E0;
	return (color);
}
