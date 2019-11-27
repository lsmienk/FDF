/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colourconvert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 11:12:33 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/13 11:12:33 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(t_melm *current, int min, int max)
{
	double	distance;
	double	place;

	place = current->val - 0;
	distance = max - min;
	if (distance == 0)
		return (1.0);
	else
		return (place / distance);
}

int				light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				colourconvert(t_melm *current, int min, int max)
{
	int		red;
	int		green;
	int		blue;
	long	hex;
	double	percentage;

	percentage = percent(current, min, max);
	red = light((GREY >> 16) & 0xFF, (PINK >> 16) & 0xFF, percentage);
	green = light((GREY >> 8) & 0xFF, (PINK >> 8) & 0xFF, percentage);
	blue = light(GREY & 0xFF, PINK & 0xFF, percentage);
	hex = (red << 16L);
	hex += green << 8L;
	hex += blue;
	return ((int)hex);
}
