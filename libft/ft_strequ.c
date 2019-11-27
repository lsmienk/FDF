/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:17:47 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 20:20:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!(char*)s1 || !(char*)s2)
		return (0);
	if (ft_strlen((char*)s1) > ft_strlen((char*)s2))
		return (ft_strnequ(s1, s2, ft_strlen((char*)s1)));
	else
		return (ft_strnequ(s1, s2, ft_strlen((char*)s2)));
}
