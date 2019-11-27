/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 15:43:42 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/26 09:04:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;

	if ((*alst) != NULL)
	{
		while (*alst != NULL)
		{
			elem = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = elem;
		}
	}
}
