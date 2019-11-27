/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:57:00 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/21 19:03:54 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = (size_t)ft_strlen((char*)src) + 1;
	if (len > i)
	{
		dst = ft_memcpy(dst, src, i);
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
