/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 14:59:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:04:37 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	j = 0;
	while (i > j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i--;
		j++;
	}
	return (s);
}
