/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:16:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 18:00:33 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	if (len > ft_strlen((char*)haystack))
		len = ft_strlen((char*)haystack);
	i = ft_strlen((char*)needle);
	if ((*needle) == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && j < len)
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, i) == 0)
			{
				if (j + i > len)
					return (NULL);
				return ((char*)haystack);
			}
		haystack++;
		j++;
	}
	return (NULL);
}
