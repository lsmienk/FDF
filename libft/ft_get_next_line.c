/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 15:06:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/17 13:31:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ret_newline(char *str, char **line, int read_in)
{
	size_t i;

	i = ft_strfroc(str, '\n');
	*line = ft_strjoinf(*line, ft_struntil(str, i));
	if (str[i + 1])
		str = ft_strtailf(&str, i + 1);
	else
		ft_strclr(str);
	if (!str || !*line)
		return (-1);
	if (ft_strlen(*line) > 0 || read_in > 0)
		return (1);
	return (read_in);
}

static int		add_to_line(char *str, char **line)
{
	if (ft_strlen(*line) == 0)
	{
		ft_strdel(line);
		*line = ft_strdup(str);
	}
	else
	{
		*line = ft_strextend(*line, ft_strlen(str));
		if (!*line)
			return (-1);
		*line = ft_strncat(*line, str, ft_strlen(str));
	}
	if (str)
		ft_strclr(str);
	return ((!*line) ? -1 : 1);
}

static t_gnl	*get_gnl(int fd, t_list *gnl)
{
	t_gnl	*temp_gnl;
	t_list	*tmp;

	tmp = gnl;
	temp_gnl = (t_gnl *)gnl->content;
	while (tmp->next && ((t_gnl*)(tmp->content))->fd != fd)
		tmp = tmp->next;
	return ((((t_gnl*)(tmp->content))->fd == fd) ?
		(t_gnl *)(tmp->content) : NULL);
}

static int		create_lst(t_list **gnl, int fd)
{
	t_gnl	*g;
	t_list	*gnl2;

	if (*gnl && get_gnl(fd, *gnl) != NULL)
		return (1);
	g = (t_gnl*)ft_memalloc(sizeof(t_gnl));
	if (!g)
		return (-1);
	g->fd = fd;
	ft_strclr(g->fds);
	gnl2 = ft_lstnew(NULL, 0);
	gnl2->content = g;
	gnl2->content_size = sizeof(g);
	if (!gnl2)
		return (-1);
	ft_lstadd(gnl, gnl2);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_gnl			*cur_gnl;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (!*line || create_lst(&gnl, fd) == -1)
		return (-1);
	i = 1;
	cur_gnl = NULL;
	cur_gnl = get_gnl(fd, gnl);
	while (i > 0 && ft_strchr(cur_gnl->fds, '\n') == NULL)
	{
		if (ft_strlen(cur_gnl->fds) > 0)
			i = add_to_line(cur_gnl->fds, line);
		if (i == -1)
			return (-1);
		i = read(fd, cur_gnl->fds, BUFF_SIZE);
		if (i == -1)
			return (-1);
	}
	return (ret_newline(cur_gnl->fds, line, i));
}
