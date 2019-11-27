/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hextoint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 15:59:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/13 15:59:01 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_hexttoint(char c)
{
	if (c >= 'A' && c <= 'F')
		return ((c - 'A') + 10);
	else if (c >= 'a' && c <= 'f')
		return ((c - 'a') + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}
