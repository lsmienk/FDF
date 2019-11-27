/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:28:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 14:54:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int sl1;
	int sl2;

	if (n == 0)
		return (0);
	sl1 = ft_strlen((char*)s1);
	sl2 = ft_strlen((char*)s2);
	if (sl1 == sl2 && (int)n >= sl1 + 1)
		return (ft_memcmp(s1, s2, sl1));
	if ((int)n < sl1 + 1)
		return (ft_memcmp(s1, s2, n));
	return (ft_memcmp(s1, s2, sl1 + 1));
}
