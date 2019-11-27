/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parallelproject.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 15:24:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 17:40:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*parallelproject(t_point *pos, t_point *offset)
{
	pos->x = (pos->x + offset->x) + (pos->z + offset->z);
	pos->y = (pos->z + offset->z) - (pos->y + offset->y);
	pos->z = 0;
	return (pos);
}
