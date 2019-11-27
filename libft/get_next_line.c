/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 16:45:36 by lsmienk        #+#    #+#                */
/*   Updated: 2019/04/24 11:01:41 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		end_of_line(char *store)
{
	int	i;

	i = 0;
	while (store[i])
	{
		if (store[i] == '\n')
			break ;
		i++;
	}
	if (store[i] == '\n')
	{
		store[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

static int		check(char **store, char *tmp, char **line)
{
	int		last;
	char	*new;
	char	*ptr;

	new = ft_strjoin(*store, tmp);
	if (!new)
		return (-1);
	ft_strdel(store);
	*store = new;
	last = end_of_line(*store);
	if (last > -1)
	{
		*line = ft_strdup(*store);
		if (!*line)
			return (-1);
		ptr = ft_strdup(*store + last + 1);
		if (!*store)
			return (-1);
		free(*store);
		*store = ptr;
		return (1);
	}
	return (0);
}

static int		read_text(const int fd, char **store, char *tmp, char **line)
{
	int	x;
	int	result;

	x = 1;
	while (x > 0)
	{
		x = (int)read(fd, tmp, BUFF_SIZE);
		if (x < 0)
			return (-1);
		result = check(&store[fd], tmp, line);
		if (result == 1)
			return (1);
		ft_strclr(tmp);
	}
	result = (check(&store[fd], tmp, line));
	if (ft_strlen(store[fd]) > 0 && result <= 0)
	{
		*line = ft_strdup(store[fd]);
		if (!*line)
			return (-1);
		ft_strdel(&store[fd]);
		return (1);
	}
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	static char	*store[12000];
	char		*tmp;
	int			result;

	result = 0;
	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > 12000)
		return (-1);
	tmp = ft_strnew(BUFF_SIZE);
	if (!tmp)
		return (-1);
	if (!store[fd])
		store[fd] = ft_strnew(0);
	result = read_text(fd, store, tmp, line);
	free(tmp);
	return (result);
}
