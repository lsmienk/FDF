/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 10:13:12 by lsmienk        #+#    #+#                */
/*   Updated: 2019/04/25 11:03:05 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 60

int		get_next_line(const int fd, char **line);

#endif
