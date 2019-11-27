/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtailf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 11:53:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/17 19:08:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtailf(char **str, size_t i)
{
	char *s1;

	s1 = ft_strtail(*str, i);
	ft_strclr(*str);
	ft_strcpy(*str, s1);
	ft_strdel(&s1);
	return (*str);
}
