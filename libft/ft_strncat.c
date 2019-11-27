/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:28:46 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 18:08:22 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	j = (size_t)ft_strlen((char*)s1);
	i = (size_t)ft_strlen((char*)s2);
	if (i < n)
		ft_strcpy(s1 + j, s2);
	else
	{
		ft_strncpy(s1 + j, s2, n);
		s1[j + n] = '\0';
	}
	return (s1);
}
