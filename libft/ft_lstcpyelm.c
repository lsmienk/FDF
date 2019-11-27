/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcpyelm.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 16:14:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:08:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpyelm(t_list *elem)
{
	t_list *elem1;

	if (!elem)
		return (NULL);
	elem1 = ft_lstnew(elem->content, elem->content_size);
	return (elem1);
}
