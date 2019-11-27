/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 13:38:09 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 19:54:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s) - 1;
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i] = f(s[i]);
		i--;
	}
	return (str);
}
