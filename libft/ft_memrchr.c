/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 14:28:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:05:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned const char *d;
	unsigned const char *f;

	if (!s || (int)n < 0)
		return (NULL);
	d = (unsigned char *)s;
	f = NULL;
	while (n > 0)
	{
		if (*d == (unsigned char)c)
			f = d;
		d++;
		n--;
	}
	return ((void *)f);
}
