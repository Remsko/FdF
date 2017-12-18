/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:52:58 by rpinoit           #+#    #+#             */
/*   Updated: 2017/12/18 19:05:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		check_map(char *z)
{
	int	i;

	i = ft_strlen(z);
	if ((i > 0 && ft_isdigit(z[0])) || (z[0] == '-' && i > 1 \
				&& ft_isdigit(z[1])))
		return (1);
	else
		return (0);
}

static void		get_map(t_map *map, t_list *lst, t_env *env)
{
	int		x;
	int		y;
	t_list	*tmp;

	tmp = lst;
	if (!(map->points = (t_points**)malloc(sizeof(t_points*) * env->height)))
		ft_error(8);
	y = -1;
	while (lst && map)
	{
		if (!(map->points[++y] = (t_points*)malloc(sizeof(t_points) \
						* env->width)))
			ft_error(8);
		x = -1;
		while (++x < env->width)
		{
			map->points[y][x].x = x * 10;
			map->points[y][x].y = y * 10;
			if (!(check_map(((char**)lst->content)[0])))
				ft_error(4);
			map->points[y][x].z = ft_atoi(((char**)lst->content)[x]) * 10;
		}
		lst = lst->next;
	}
	ft_lstdel(&tmp, ft_deltab);
}

static void		init_map(int fd, char *path, t_map *map, t_env *env)
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
	get_map(map, lst, env);
}

t_map			*read_file(char *path, t_env *env)
{
	t_map	*map;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(path, O_RDONLY)) <= 0)
		ft_error(2);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_error(8);
	init_map(fd, path, map, env);
	if (env->height <= 1)
		ft_error(4);
	if (close(fd) == -1)
		ft_error(9);
	return (map);
}
