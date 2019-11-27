/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 14:47:21 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 12:34:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntdigits(int n)
{
	int i;

	i = 0;
	while (n / 10 != 0 || n % 10 != 0)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_handleneg(char *str, int *neg, int n, int i)
{
	if (n < 0)
	{
		str = ft_strnew(i + 1);
		*neg = 1;
	}
	else
	{
		str = ft_strnew(i);
		*neg = 0;
	}
	return (str);
}

static char	*ft_handlenend(int i, int neg, char *str)
{
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_cntdigits(n);
	str = NULL;
	str = ft_handleneg(str, &neg, n, i);
	if (!str)
		return (NULL);
	i = 0;
	while (n / 10 != 0 || n % 10 != 0)
	{
		str[i] = ft_toabs(n % 10) + '0';
		n /= 10;
		i++;
	}
	return (ft_handlenend(i, neg, str));
}
