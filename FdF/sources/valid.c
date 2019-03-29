/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:02:33 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/24 12:14:12 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> // delete.

static int	valid_alpha_digit(char *line, int q)
{
	int		r;

	r = 1;
	while (r != 6)		//	Числу в 16-й кодировке не обязательно быть 6-разрядным (например, черный цвет может быть выражен числом 0x0, а синий - 0x80, и это будет валидным числом)
	{
		if ((line[q + r] < 48 || line[q + r] > 57) && (line[q + r] < 65
		|| line[q + r] > 70) && (line[q + r] < 97 || line[q + r] > 102))
			error_message(98);
		r++;
	}
	q += r;
	return (q);
}

static void	valid_symbols(char *line)
{
	int		q;

	q = 0;
	while (line[q])
	{
		if (line[q] != ' ' && line[q] != '\t')
		{
			if (line[q] == ',')
			{
				if (line[q + 1] != '0' && line[q + 2] != 'x')
					error_message(98);
				q += 3;
				q = valid_alpha_digit(line, q);
			}
			if (line[q] != '-' && (line[q] < 48 || line[q] > 57)
			&& line[q] != ' ' && line[q] != '\t')
				error_message(98);

		}
		q++;
	}
}

static int	count_coord(char *line)
{
	int 	q;
	int 	count;
	int 	len;

	q = 0;
	count = 0;
	len = ft_strlen(line);
	while (line[q] == ' ' || line[q] == '\t')
		q++;
	while (q < len)
	{
		if (line[q] != ' ' && line[q] != '\t')
		{
			count++;
			while (line[q] != ' ' && line[q] != '\t' && line[q])
				q++;
		}
		q++;
	}
	return (count);
}

void		is_map_valid(char **argv, t_map *map)
{
	int		fd;
	char 	*line;
	int 	last;
	int 	next;
	int 	r;

	next = 0;
	last = 0;
	r = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message(1);
	while (get_next_line(fd, &line))
	{
		next = count_coord(line);
		valid_symbols(line);
		if (next != last && last != 0)
			error_message(99);
		last = next;
		r++;

	}
	map->width = next;
	map->height = r;
	map->focus = 1;
}

