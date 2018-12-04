/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:42:12 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/07 18:44:02 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "validation.h"

int	read_stdinput(void)		/*функция чтения карты со стандартного ввода*/
{							/*не работает, что-то идет не так при чтении*/
	int		fd;
	int		buf_size;
	int		file_size;
	char	buf[1024];
	char	*map;

	fd = open("no_arg_map", O_RDWR | O_CREAT);
	file_size = 0;
	while ((buf_size = read(0, buf, 1024)))
		write(fd, buf, 1024);
	close(fd);
	map = (char *)malloc(sizeof(char) * (file_size + 1));
	fd = open("no_arg_map", O_RDONLY); /*у нас есть пустой файл no_arg_map*/
	buf_size = read(fd, map, file_size); /*и он принимает в себя все, что мы введем с клавиатуры*/
	printf("%s", map);
	close(fd);
	if (!firstline_is_valid(map) || !map_is_valid(map))
		return (0);
	return (1);
}

void	bsq(int files, char **input)
{
	int i;

	i = 1;
	if (files == 1)
		if (read_stdinput())
			write(1, "krasava, vse norm", 17);
	while (i < files)
	{
		if (input_is_valid(input[i]))
			/*solve_map(input[i]);*/
			write(1, "krasava, vse norm", 17);
		else
			write(2, "map error\n", 10);
		i++;
	}
}

int		main(int argc, char **argv)
{
	bsq(argc, argv);
	return (0);
}
