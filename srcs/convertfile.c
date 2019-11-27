/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convertfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:27:10 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/10 17:34:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	strtocolour(char **str)
{
	int		r;
	int		b;
	int		g;
	long	hex;

	r = (ft_hexttoint(str[1][2]) << (4 * 1) & 0xff);
	r += (ft_hexttoint(str[1][3]) << (4 * 0) & 0xff);
	g = (ft_hexttoint(str[1][4]) << (4 * 1) & 0xff);
	g += (ft_hexttoint(str[1][5]) << (4 * 0) & 0xff);
	b = (ft_hexttoint(str[1][6]) << (4 * 1) & 0xff);
	b += (ft_hexttoint(str[1][7]) << (4 * 0) & 0xff);
	ft_strdel(&str[0]);
	ft_strdel(&str[1]);
	free(str);
	hex = (r << 16L);
	hex += g << 8L;
	hex += b;
	return ((int)(hex));
}

static void	freesplits(char **split, int size)
{
	size--;
	while (size >= 0)
	{
		ft_strdel(&split[size]);
		size--;
	}
	free(split);
}

static void	dowork(t_map *map, int vals[2], int *i, char **split)
{
	map->map[vals[0]][vals[1]].val = ft_atoi(split[*i]);
	if (map->map[vals[0]][vals[1]].val < map->min)
		map->min = map->map[vals[0]][vals[1]].val;
	if (map->map[vals[0]][vals[1]].val > map->max)
		map->max = map->map[vals[0]][vals[1]].val;
	if (ft_strcc(split[*i], ',') == 1)
		map->map[vals[0]][vals[1]].colour =
				strtocolour(ft_strsplit(split[*i], ','));
	else
		map->map[vals[0]][vals[1]].colour = -1;
	(*i)++;
}

static int	placeinmap(t_list *elem, t_map *map, int y)
{
	char	**split;
	int		i;
	int		x;

	split = rowtoarray((char*)elem->content, map);
	if (split == NULL)
		return (0);
	x = 0;
	i = 0;
	map->map[y] = (t_melm*)ft_memalloc(sizeof(t_melm) * map->map_size.x);
	if (map->map[y] == NULL)
		return (0);
	while (x < map->map_size.x && split[i])
	{
		dowork(map, (int[]){y, x}, &i, split);
		x++;
	}
	while (x < map->map_size.x)
	{
		map->map[y][x].val = 0;
		map->map[y][x].colour = -1;
		x++;
	}
	freesplits(split, i);
	return (1);
}

t_map		*convertfile(t_map *map, t_list *lst)
{
	t_list	*elem;
	int		y;

	map->map_size.y = ft_lstcnt(lst);
	map->map_size.x = -2147483648;
	map->min = 2147483647;
	map->max = -2147483648;
	map->map = (t_melm**)ft_memalloc(sizeof(t_melm*) * map->map_size.y);
	elem = lst;
	y = 0;
	while (y < map->map_size.y)
	{
		if (!placeinmap(elem, map, y))
			return (NULL);
		elem = elem->next;
		y++;
	}
	return (map);
}
