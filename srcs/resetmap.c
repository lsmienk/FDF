/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resetmap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 12:05:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/14 12:05:48 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		resetmap(t_map *map)
{
	map->zoom = 10;
	map->rotation.x = 1.5708;
	map->rotation.y = 0;
	map->rotation.z = 0;
	map->transform.z = 320;
	if (map->projection == isoproject || map->projection == fisoproject)
	{
		map->transform.x = 200;
		map->transform.y = -300;
	}
	else if (map->projection == parallelproject)
	{
		map->transform.x = 160;
		map->transform.y = 0;
	}
	else if (map->projection == normalproject)
	{
		map->transform.x = 500;
		map->transform.y = 0;
	}
	setrotmatrix(map);
}
