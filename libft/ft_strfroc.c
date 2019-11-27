/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfroc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 12:08:54 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/05 12:12:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strfroc(char *str, char c)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
