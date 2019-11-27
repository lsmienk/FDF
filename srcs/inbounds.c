/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inbounds.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:49:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/05 16:56:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	inbounds(int x, int y)
{
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		return (1);
	return (0);
}
