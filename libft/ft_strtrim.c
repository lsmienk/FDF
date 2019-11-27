/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:50:39 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 19:42:36 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_getlengthww(char *str)
{
	int i;
	int j;

	j = ft_skipwhitespace(str, 0);
	i = ft_strlen(str);
	while (j < i)
	{
		if (ft_skipwhitespace(str, j) >= i)
		{
			return (j);
		}
		j++;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = ft_skipwhitespace((char*)s, 0);
	str = ft_strnew(ft_getlengthww((char*)s) - i);
	if (!str)
		return (NULL);
	ft_strncpy(str, &(s[i]), ft_getlengthww((char*)s) - i);
	return (str);
}
