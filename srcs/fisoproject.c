/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fisoproject.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 15:08:21 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 16:17:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*fisoproject(t_point *pos, t_point *offset)
{
	int		pre_x;
	int		pre_z;
	int		pre_y;

	pre_x = (pos->x + offset->x);
	pre_z = (pos->z + offset->z);
	pre_y = (pos->y + offset->y);
	pos->x = (pre_x + pre_z) * cos(0.46373398);
	pos->y = ((pre_x - pre_z) * -sin(0.46373398)) - pre_y;
	pos->z = 0;
	return (pos);
}
