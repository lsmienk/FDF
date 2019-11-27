/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdfloop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:54:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 11:34:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdfloop(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	bcolour(mlx, BLACK);
	drawmap(mlx->map, mlx);
	mlx_put_image_to_window(mlx->info, mlx->win, mlx->img, 0, 0);
	drawinfo(mlx, LIME);
	return (1);
}
