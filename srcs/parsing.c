/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:52:58 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/14 18:37:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_color(char *str)
{
	int color;

	color = 0;
	while (*str)
	{
		if (*str == ',')
			color = ft_atoi_base(str + 1, 10);
		else
			str++;
	}
	if (color < 0 || color > (255 * 255 * 255))
		ft_error(4);
	return (color);
}

static int	check_map(char *z)
{
	int	i;

	i = ft_strlen(z);
	if ((i > 0 && ft_isdigit(z[0])) || (z[0] == '-' && i > 1 && ft_isdigit(z[1])))
			return (1);
	else
			return (0);
}

static void	get_map(t_list *lst, t_env *env)
{
	int 	x;
	int 	y;
	t_list	*tmp;

	tmp = lst;
	if (!(env->map = (t_map**)malloc(sizeof(t_map*) * env->height)))
		ft_error(8);
	y = -1;
	while (lst && env->map && ++y < env->width)
	{
		if (!(env->map[y] = (t_map*)malloc(sizeof(t_map) * env->width)))
			ft_error(8);
		x = -1;
		while (++x < env->width)
		{
			env->map[y][x].x = x * 10;
			env->map[y][x].y = y * 10;
			if (!(check_map(((char**)lst->content)[0])))
				ft_error(4);
			env->map[y][x].z = ft_atoi(((char**)lst->content)[x]) * 10;
			env->map[y][x].color = get_color(((char**)lst->content)[x]);
		}
		lst = lst->next;
	}
	ft_lstdel(&tmp, ft_deltab);
}

static void	init_map(int fd, char *path, t_env *env)
{
	char	**split;
	t_list	*lst;

	env->width = 0;
	env->height = 0;
	while (get_next_line(fd, &path) > 0)
	{
		split = ft_strsplit(path, ' ');
		ft_strdel(&path);
		if (env->height++ == 0)
		{
			env->width = ft_tablen(split);
			if (!(lst = ft_lstnew(&split, sizeof(char**))))
				ft_error(8);
			lst->content = (void*)split;
		}
		else
		{
			if (ft_tablen(split) != env->width)
				ft_error(8);
			ft_lstadd(&lst, ft_lstnew(&split, sizeof(char**)));
			lst->content = (void*)split;
		}
	}
	get_map(lst, env);
}

t_env	*read_file(char *path, t_env *env)
{
	int		fd;

	if ((fd = open(path, O_RDONLY)) <= 0)
		ft_error(2);
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error(8);
	init_map(fd, path, env);
	if (close(fd) == -1)
		ft_error(9);
	return (env);
}
