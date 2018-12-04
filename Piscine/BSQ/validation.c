/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:29:14 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/07 18:07:47 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int		same_length(char *map)
{
	int	i;
	int	len;
	int	len_n;

	i = 0;
	len = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i++] != '\n')
		len++;
	while (map[i])
	{
		len_n = 0;
		while (map[i] != '\n' && map[i])
		{
			len_n++;
			i++;
		}
		if (len != len_n)
			return (0);
		i++;
	}
	return (1);
}

int		map_is_valid(char *map)
{
	int		i;
	int		lines;
	int		n_count;
	char	empt;
	char	obst;

	i = 0;
	n_count = 0;
	while (map[i] != '\n' && map[i])
		i++;
	lines = custom_atoi(map, i - 3);
	empt = map[i - 3];
	obst = map[i - 2];
	i++;
	while (map[i])
	{
		if (map[i] != empt && map[i] != obst && map[i] != '\n')
			return (0);
		if (map[i] == '\n')
			n_count++;
		i++;
	}
	if (lines != n_count || map[i - 1] != '\n' || !same_length(map))
		return (0);
	return (1);
}

int		firstline_is_valid(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n' && map[i])
		i++;
	if (map[i] != '\n' || i < 4)
		return (0);
	if (map[i - 2] == map[i - 3] || custom_atoi(map, i - 3) == -1)
		return (0);
	return (1);
}

int		input_is_valid(char *file_name)	/*функция читает файл и отправляет на проверку в две функции*/
{
	int		fd;
	int		buf_size;
	int		file_size;
	char	buf[1024];
	char	*map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	file_size = 0;
	while ((buf_size = read(fd, buf, 1024)))
		file_size += buf_size;
	close(fd);
	map = (char *)malloc(sizeof(char) * (file_size + 1));
	fd = open(file_name, O_RDONLY);
	buf_size = read(fd, map, file_size);
	printf("%s", map);
	close(fd);
	if (!firstline_is_valid(map) || !map_is_valid(map))	/*первая проверяет валидность первой строки, вторая - всей карты*/
		return (0);
	return (1);											/*можешь вообще не трогать функции в этом файле, они на 100% рабочие*/
}
