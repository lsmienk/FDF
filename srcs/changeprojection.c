/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   changeprojection.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 11:52:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/14 11:52:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		changeprojection(t_mlx *mlx,
					t_point *(*projection)(t_point *pos, t_point *offset),
					t_point offset)
{
	mlx->map->projection = projection;
	mlx->map->transform.x = offset.x;
	mlx->map->transform.y = offset.y;
	mlx->map->transform.z = offset.z;
}
