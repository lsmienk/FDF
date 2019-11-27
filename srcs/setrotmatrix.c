/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setrotmatrix.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 16:11:07 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/11 16:11:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		setrotmatrix(t_map *map)
{
	t_rotmatrix cossin;

	cossin.a = cos(map->rotation.y);
	cossin.b = sin(map->rotation.y);
	cossin.c = cos(map->rotation.z);
	cossin.x = sin(map->rotation.z);
	cossin.y = cos(map->rotation.x);
	cossin.z = sin(map->rotation.x);
	map->rotmatrix.a = cossin.a * cossin.c;
	map->rotmatrix.b = (cossin.a * cossin.x * cossin.z)
		- (cossin.b * cossin.y);
	map->rotmatrix.c = (cossin.a * cossin.x * cossin.y)
		+ (cossin.b * cossin.z);
	map->rotmatrix.i = cossin.b * cossin.c;
	map->rotmatrix.j = (cossin.b * cossin.x * cossin.z)
		+ (cossin.a * cossin.y);
	map->rotmatrix.k = (cossin.b * cossin.x * cossin.y)
		- (cossin.a * cossin.z);
	map->rotmatrix.x = -cossin.x;
	map->rotmatrix.y = cossin.c * cossin.z;
	map->rotmatrix.z = cossin.c * cossin.y;
}
