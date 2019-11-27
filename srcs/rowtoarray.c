/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rowtoarray.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 13:14:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 17:34:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	getdarraysize(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			j++;
			while (str[i + 1] == ' ')
				i++;
		}
		i++;
	}
	if (str[i - 1] == ' ')
		return (j);
	return (j + 1);
}

static size_t	gettilnextspace(char *str, size_t i)
{
	size_t j;

	j = i;
	while (str[j] && str[j] != ' ')
		j++;
	return (j - i);
}

static size_t	getnextnum(char *str, size_t i)
{
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

static size_t	getstartnum(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

char			**rowtoarray(char *str, t_map *map)
{
	char	**ar;
	size_t	m_size;
	size_t	i;
	size_t	j;

	m_size = getdarraysize(str);
	ar = (char**)ft_memalloc(sizeof(char*) * (m_size + 1));
	i = 0;
	j = getstartnum(str);
	while (i < m_size && str[j])
	{
		ar[i] = ft_strinit(&(str[j]), gettilnextspace(str, j));
		j = getnextnum(str, j);
		i++;
	}
	if (map->map_size.x != m_size && map->map_size.x != -2147483648)
		return (NULL);
	else
		map->map_size.x = m_size;
	return (ar);
}
