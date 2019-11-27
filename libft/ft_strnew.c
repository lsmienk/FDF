/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 15:59:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/09 12:32:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((int)size < 0)
		return (NULL);
	str = (char*)ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	return (str);
}
