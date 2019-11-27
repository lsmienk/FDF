/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:10:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 18:07:04 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pt1;
	const unsigned char	*pt2;
	size_t				i;

	i = 0;
	pt1 = dst;
	pt2 = src;
	while (i < n && (i == 0 || pt1[i - 1] != (unsigned char)c))
	{
		pt1[i] = pt2[i];
		i++;
	}
	if (i > 0 && pt2[i - 1] == (unsigned char)c)
		return (&(dst[i]));
	return (NULL);
}
