/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 15:38:54 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 16:27:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	checknum(char *elem, int i)
{
	if (elem[i + 1] && elem[i] == '-' && ft_isdigit(elem[i + 1]))
		return (1);
	return (ft_isdigit(elem[i]));
}

static int	isvalidhexcode(char *elem, size_t place)
{
	size_t i;

	i = 0;
	while (i < 6)
	{
		if (!ft_ishex(elem[place + i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ishex(int *i, char *elem)
{
	long j;

	j = (long)(*i);
	if ((long)ft_strlen(elem) - (j + 9) < 0)
		return (0);
	if (!(elem[j] == ',' && elem[j + 1] == '0' && elem[j + 2] == 'x'))
		return (0);
	if (!isvalidhexcode(elem, (size_t)(j + 3)))
		return (0);
	if (elem[j + 9] && elem[j + 9] != ' ')
		return (0);
	*i = (int)j + 9;
	return (1);
}

static int	carcheck(char *elem)
{
	int i;

	i = 0;
	while (elem[i])
	{
		while (checknum(elem, i) || elem[i] == ' ')
			i++;
		if (elem[i] && !ishex(&i, elem))
			return (0);
	}
	return (1);
}

int			validate(t_list *lst)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = lst;
	while (elem != NULL)
	{
		if (!carcheck((char *)elem->content))
			return (0);
		elem = elem->next;
		i++;
	}
	return (1);
}
