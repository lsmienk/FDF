/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:41:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 19:13:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(long *i, long *neg, char *str)
{
	if (str[*i] == '-')
	{
		*neg = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		*neg = 1;
		(*i)++;
	}
	else
		*neg = 1;
}

int			ft_atoi(const char *str)
{
	long	i;
	long	j;
	long	neg;

	j = 0;
	i = ft_skipwhitespace((char*)str, 0);
	ft_neg(&i, &neg, (char*)str);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			j *= 10;
			j += str[i] - '0';
		}
		else if (((str[i] != '-' || str[i] != '+'))
			|| str[i] == '\e')
			break ;
		i++;
	}
	return (neg * j);
}
