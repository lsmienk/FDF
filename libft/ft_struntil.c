/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struntil.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 14:12:46 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/08 14:16:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_struntil(char *s1, size_t i)
{
	char	*s2;
	size_t	j;

	j = (ft_strlen(s1) < i) ? ft_strlen(s1) : i;
	s2 = ft_strnew(j);
	s2 = ft_strncpy(s2, s1, j);
	s2[j] = '\0';
	return (s2);
}
