/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 15:52:57 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/11 15:52:57 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*rotate(t_point *pos, t_rotmatrix *matrix,
						t_point *mapsize, double zoom)
{
	double x;
	double y;
	double z;

	x = pos->x - ((mapsize->x / 2) * zoom);
	y = pos->y;
	z = pos->z - ((mapsize->y / 2) * zoom);
	pos->x = (matrix->a * x) + (matrix->b * y) + (matrix->c * z);
	pos->y = (matrix->i * x) + (matrix->j * y) + (matrix->k * z);
	pos->z = (matrix->x * x) + (matrix->y * y) + (matrix->z * z);
	return (pos);
}
