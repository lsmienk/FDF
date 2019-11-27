/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalproject.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 16:55:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 17:27:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*normalproject(t_point *pos, t_point *offset)
{
	pos->x = pos->x + offset->x;
	pos->y = (pos->z + offset->z) - (pos->y + offset->y);
	pos->z = 0;
	return (pos);
}
