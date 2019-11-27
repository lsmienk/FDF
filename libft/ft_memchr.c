/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 14:12:26 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/22 14:58:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)s;
	while (n > 0)
	{
		if (*d == (unsigned char)c)
			return ((void*)d);
		d++;
		n--;
	}
	return (NULL);
}
