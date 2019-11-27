/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readfile.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:36:55 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/05 16:26:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		freecontent(void *content, size_t contentsize)
{
	contentsize++;
	ft_memdel(&content);
}

static t_list	*freereturn(t_list *map)
{
	ft_lstdel(&map, freecontent);
	return (NULL);
}

t_list			*readfile(int fd)
{
	t_list	*map;
	t_list	*elm;
	t_list	*prv;
	char	*s1;

	map = NULL;
	s1 = NULL;
	while (ft_get_next_line(fd, &s1) == 1)
	{
		elm = ft_lstnew(NULL, 0);
		if (!elm)
			return (freereturn(map));
		if (map == NULL)
			map = elm;
		else
			prv->next = elm;
		elm->content = (void*)s1;
		elm->content_size = sizeof(s1);
		prv = elm;
	}
	ft_strdel(&s1);
	return (map);
}
