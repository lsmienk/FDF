/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switchpos.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 11:11:31 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/11 11:12:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		switchpos(t_point *pos1, t_point *pos2)
{
	t_point buf;

	buf.x = pos1->x;
	buf.y = pos1->y;
	pos1->x = pos2->x;
	pos1->y = pos2->y;
	pos2->x = buf.x;
	pos2->y = buf.y;
}
