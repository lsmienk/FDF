/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strextend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 13:34:41 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/10 15:15:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strextend(char *str, size_t len)
{
	if (!str)
		return (NULL);
	return ((char *)ft_realloc(str, sizeof(char) * (ft_strlen(str) + len + 1),
		ft_strlen(str)));
}
