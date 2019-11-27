/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 14:18:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 17:38:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawmapz(t_mlx *mlx, int x, int z)
{
	t_point	pos1;
	t_point	pos2;

	pos1 = (t_point){x * mlx->map->zoom, z * mlx->map->zoom,
			(mlx->map->map[z][x].val * mlx->map->zoom) * mlx->map->ymulti};
	pos2 = (t_point){x * mlx->map->zoom, (z * mlx->map->zoom) + mlx->map->zoom,
			(mlx->map->map[z + 1][x].val * mlx->map->zoom) * mlx->map->ymulti};
	mlx->map->projection(rotate(&pos1, &(mlx->map->rotmatrix),
				&(mlx->map->map_size), mlx->map->zoom), &(mlx->map->transform));
	mlx->map->projection(rotate(&pos2, &(mlx->map->rotmatrix),
				&(mlx->map->map_size), mlx->map->zoom), &(mlx->map->transform));
	if (mlx->map->map[z][x].colour == -1)
		mlx->map->map[z][x].colour =
			colourconvert(&(mlx->map->map[z][x]), mlx->map->min, mlx->map->max);
	drawline(&pos1, &pos2, mlx->img_add, mlx->map->map[z][x].colour);
}

static void	drawmapx(t_mlx *mlx, int x, int z)
{
	t_point	pos1;
	t_point	pos2;

	pos1 = (t_point){(x * mlx->map->zoom), (z * mlx->map->zoom),
			(mlx->map->map[z][x].val * mlx->map->zoom) * mlx->map->ymulti};
	pos2 = (t_point){(x * mlx->map->zoom) + mlx->map->zoom,
			(z * mlx->map->zoom),
			(mlx->map->map[z][x + 1].val * mlx->map->zoom) * mlx->map->ymulti};
	mlx->map->projection(rotate(&pos1, &(mlx->map->rotmatrix),
				&(mlx->map->map_size), mlx->map->zoom), &(mlx->map->transform));
	mlx->map->projection(rotate(&pos2, &(mlx->map->rotmatrix),
				&(mlx->map->map_size), mlx->map->zoom), &(mlx->map->transform));
	if (mlx->map->map[z][x].colour == -1)
		mlx->map->map[z][x].colour =
			colourconvert(&(mlx->map->map[z][x]), mlx->map->min, mlx->map->max);
	drawline(&pos1, &pos2, mlx->img_add, mlx->map->map[z][x].colour);
}

void		drawmap(t_map *map, t_mlx *mlx)
{
	int x;
	int z;

	z = 0;
	while (z < map->map_size.y)
	{
		x = 0;
		while (x < map->map_size.x)
		{
			if (z != map->map_size.y - 1)
				drawmapz(mlx, x, z);
			if (x != map->map_size.x - 1)
				drawmapx(mlx, x, z);
			x++;
		}
		z++;
	}
}
