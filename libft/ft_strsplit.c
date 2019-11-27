/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:51:03 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:11:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_setword(char **s1, char *s2, int *k, char c)
{
	int i;
	int size;

	i = *k;
	while (s2[i] && s2[i] != c)
		i++;
	size = (i - *k);
	*s1 = ft_strnew(size);
	*s1 = ft_strncpy(*s1, &s2[*k], size);
	*k = *k + size;
}

static int	ft_countwords(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
			continue ;
		}
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**ar;

	if (!(char*)s || !c)
		return (NULL);
	i = ft_strskip((char*)s, c, 0);
	j = 0;
	ar = (char**)ft_memalloc((ft_countwords((char*)s, c) + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	while (j < ft_countwords((char *)s, c))
	{
		i = ft_strskip((char*)s, c, i);
		ft_setword(&ar[j], (char*)s, &i, c);
		j++;
	}
	ar[j] = 0;
	return (ar);
}
