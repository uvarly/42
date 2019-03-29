/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:29:57 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/17 13:14:52 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	erase_storage(char ***storage)
{
	size_t	i;

	i = 3;
	while (i < 10240)
	{
		if ((*storage)[i])
			free((*storage)[i]);
		(*storage)[i] = 0;
		i++;
	}
	if ((*storage)[0])
	{
		free((*storage)[0]);
		(*storage)[0] = 0;
	}
	free(*storage);
	*storage = 0;
}

static int	read_from_file(char **cell, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(temp = (*cell) ? ft_strjoin(*cell, buf) : ft_strdup(buf)))
			return (0);
		if (*cell)
			free(*cell);
		*cell = temp;
	}
	if (ret < 0)
		return (0);
	return (1);
}

static int	write_to_line(char **cell, char **line)
{
	char	*delta;
	char	*temp;

	if (!*cell || !**cell)
		return (0);
	delta = ft_strchr(*cell, '\n');
	if (delta)
	{
		if (!(*line = ft_strndup(*cell, delta - *cell)))
			return (-1);
		temp = ft_strdup(delta + 1);
		free(*cell);
		*cell = temp;
		return (1);
	}
	if (!delta)
	{
		if (!(*line = ft_strdup(*cell)))
			return (-1);
		free(*cell);
		*cell = 0;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	**storage;

	if (fd < 0 || fd > 10240 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!storage)
		if (!(storage = (char **)malloc(sizeof(char *) * 10241)))
			return (-1);
	if (!storage[fd])
		if (!read_from_file(&storage[fd], fd))
		{
			erase_storage(&storage);
			return (-1);
		}
	return (write_to_line(&storage[fd], line));
}
