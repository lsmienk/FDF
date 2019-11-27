/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 08:54:40 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/26 09:03:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*elm;

	elm = *(alst);
	elm->next = NULL;
	del(elm->content, elm->content_size);
	free(elm);
	*(alst) = NULL;
}
