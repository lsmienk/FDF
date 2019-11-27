/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:37:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 18:08:09 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ((size_t)(ft_strlen((char *)dst)) < size) ?
		(size_t)ft_strlen(dst) : size;
	i = 0;
	while (src[i] != '\0' && (j + i + 1) < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (size > j)
		dst[i + j] = '\0';
	if (size < i + j)
		return (size);
	return (j + ft_strlen((char *)src));
}
