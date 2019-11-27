/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:29:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 20:06:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if ((int)len < 0 || !(char*)s)
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, &s[start], len);
	return (str);
}
