/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strskip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 12:17:39 by ehollidg       #+#    #+#                */
/*   Updated: 2019/03/29 13:10:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strskip(char *s, char c, int i)
{
	if (i < 0 || !s)
		return (i);
	while (s[i] && s[i] == c)
		i++;
	return (i);
}
