/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:00:20 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/09 11:58:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pt1;
	const char	*pt2;
	size_t		i;

	pt1 = (char *)dst;
	pt2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		pt1[i] = pt2[i];
		i++;
	}
	return (dst);
}
