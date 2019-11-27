/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 16:05:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/27 12:51:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *elem1;

	if (!lst)
		return (NULL);
	elem = f(lst);
	elem1 = elem;
	while (lst->next)
	{
		lst = lst->next;
		elem->next = f(lst);
		if (!elem->next)
		{
			return (NULL);
		}
		elem = elem->next;
	}
	return (elem1);
}
