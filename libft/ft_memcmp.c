/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:09:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 11:58:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *pt1;
	const unsigned char *pt2;
	int					i;

	if ((int)n <= 0)
		return (0);
	pt1 = (const unsigned char*)s1;
	pt2 = (const unsigned char*)s2;
	i = 0;
	while (i < (int)n)
	{
		if (pt1[i] != pt2[i])
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (pt1[i - 1] - pt2[i - 1]);
}
