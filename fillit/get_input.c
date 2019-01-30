/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:04:04 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:04:05 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	is_input_valid(char *input)
{
	short	blocks;
	short	dots;
	short	i;

	blocks = 0;
	dots = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '#')
			blocks++;
		if (input[i] == '.')
			dots++;
		if (i % 5 == 4 && input[i] != '\n')
			return (0);
		i++;
	}
	return ((blocks == 4 && dots == 12 && i == 20) ? 1 : 0);
}

int			get_input(char ***input, char *file_name)
{
	int		fd;
	char	buf[21];
	short	i;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	i = 0;
	if (!(read(fd, buf, 20) == 20))
		return (0);
	buf[20] = 0;
	if (!is_input_valid(buf))
		return (0);
	(*input)[i++] = strdup(buf);
	while (read(fd, buf, 1) == 1)
	{
		if (buf[0] != '\n' || i == 26)
			return (0);
		if (!(read(fd, buf, 20) == 20))
			return (0);
		buf[20] = 0;
		if (!is_input_valid(buf))
			return (0);
		(*input)[i++] = strdup(buf);
	}
	return (1);
}
