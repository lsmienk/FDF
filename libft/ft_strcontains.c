/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcontains.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:33:47 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:02:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcontains(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	if (!(char*)s1 || !(char*)s2)
		return (0);
	k = ft_strlen((char*)s2);
	while (s1[i] && s1[i + k - 1])
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s1[i] == s2[j])
				j++;
			if (j == k)
				return (1);
		}
		i++;
	}
	return (0);
}
