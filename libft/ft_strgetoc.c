/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strgetoc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 13:10:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/07 13:17:54 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strgetoc(char *str, char c, size_t i)
{
	size_t j;
	size_t k;

	if (!str)
		return (0);
	j = 0;
	k = 0;
	while (str[j] && k < i)
	{
		if (str[j] == c)
			k++;
		j++;
	}
	return (j);
}
