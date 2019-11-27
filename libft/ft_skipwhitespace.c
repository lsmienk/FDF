/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipwhitespace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:04:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:03:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skipwhitespace(char *str, int i)
{
	if (!str)
		return (i);
	while (str[i])
	{
		if (ft_iswhitespace(str[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}
