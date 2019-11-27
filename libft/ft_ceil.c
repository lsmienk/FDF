/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ceil.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:42:56 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 15:48:10 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_ceil(double cl)
{
	return (ft_floor(cl) != cl ? ft_floor(cl + 1) : cl);
}
