/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bcolour.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 11:47:31 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:48:21 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bcolour(t_mlx *mlx, int colour)
{
	int x;
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			plotpoint(x, y, colour, mlx->img_add);
			x++;
		}
		y++;
	}
}
