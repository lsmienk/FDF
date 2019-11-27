/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strinit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 13:30:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 13:33:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strinit(char *str, size_t size)
{
	size_t	i;
	char	*nwstr;

	i = 0;
	if (!str || size == 0)
		return (NULL);
	nwstr = ft_strnew(size);
	while (i < size)
	{
		nwstr[i] = str[i];
		i++;
	}
	return (nwstr);
}
