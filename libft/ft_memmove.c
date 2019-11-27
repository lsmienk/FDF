/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:02:54 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/22 15:28:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pt1;
	const char	*pt2;
	int			i;

	pt1 = dst;
	pt2 = src;
	if (pt1 < pt2)
	{
		i = 0;
		while (i < (int)len)
		{
			pt1[i] = pt2[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			pt1[i] = pt2[i];
			i--;
		}
	}
	return (dst);
}
