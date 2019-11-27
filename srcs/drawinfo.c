/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawinfo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:36:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 16:57:37 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		drawprotype(t_mlx *mlx, int colour, int pos)
{
	if (mlx->map->projection == normalproject)
		mlx_string_put(mlx->info, mlx->win, 1, pos, colour,
			"Projection Type : Normal Projection");
	else if (mlx->map->projection == isoproject)
		mlx_string_put(mlx->info, mlx->win, 1, pos, colour,
			"Projection Type : True Iso Projection");
	else if (mlx->map->projection == fisoproject)
		mlx_string_put(mlx->info, mlx->win, 1, pos, colour,
			"Projection Type : 2:1 Iso Projection");
	else if (mlx->map->projection == parallelproject)
		mlx_string_put(mlx->info, mlx->win, 1, pos, colour,
			"Projection Type : Parallel Projection");
}

void			drawinfo(t_mlx *mlx, int colour)
{
	mlx_string_put(mlx->info, mlx->win, 1, 1, colour, "Controls");
	mlx_string_put(mlx->info, mlx->win, 1, 20, colour, "Move : WASDZX");
	mlx_string_put(mlx->info, mlx->win, 1, 40, colour,
						"Rotate : Left, Right, Up, Down, Pg Up, Pg Down");
	mlx_string_put(mlx->info, mlx->win, 1, 60, colour, "Reset : R");
	mlx_string_put(mlx->info, mlx->win, 1, 80, colour, "Zoom : Mouse Wheel");
	mlx_string_put(mlx->info, mlx->win, 1, 100, colour, "Y Multiplier : + -");
	mlx_string_put(mlx->info, mlx->win, 1, 120, colour,
						"Change Projection : P");
	drawprotype(mlx, colour, 140);
}
