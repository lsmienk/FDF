/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 11:10:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/11 12:27:46 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		steepy(t_point *pos1, t_point *pos2, void *img_add, int colour)
{
	int x;
	int y;
	int dx;
	int dy;

	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	y = pos1->y;
	while (y < pos2->y)
	{
		x = pos1->x + dx * (y - pos1->y) / dy;
		plotpoint(x, y, colour, img_add);
		y++;
	}
}

static void		steepx(t_point *pos1, t_point *pos2, void *img_add, int colour)
{
	int x;
	int y;
	int dx;
	int dy;

	dx = pos2->x - pos1->x;
	dy = pos2->y - pos1->y;
	x = pos1->x;
	while (x < pos2->x)
	{
		y = pos1->y + dy * (x - pos1->x) / dx;
		plotpoint(x, y, colour, img_add);
		x++;
	}
}

void			drawline(t_point *pos1, t_point *pos2,
							void *img_add, int colour)
{
	if (fabs(pos2->x - pos1->x) > fabs(pos2->y - pos1->y))
	{
		if (pos1->x > pos2->x)
			steepx(pos2, pos1, img_add, colour);
		else
			steepx(pos1, pos2, img_add, colour);
	}
	else
	{
		if (pos1->y > pos2->y)
			steepy(pos2, pos1, img_add, colour);
		else
			steepy(pos1, pos2, img_add, colour);
	}
}
