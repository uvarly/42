/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:57:13 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/01 20:40:28 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

void    ft_displayerror(char *file)
{
	write(2, "cat: ", 5);
	write(2, file, ft_strlen(file));
	if (errno == 2)
		write(2, ": No such file or directory\n", 28);
	if (errno == 13)
		write(2, ": Permission denied\n", 20);
	if (errno == 21)
		write(2, ": Is a directory\n", 17);
}

void    ft_display(int argc, char **argv)
{
	int ret;
	int i = 0;
	ret = 0;
	int fb; 
	fb = 0;
	char buf[BUF_SIZE + 1];
	while (i < argc)
	{
		fb = open(argv[i], O_RDONLY);
	while ((ret = read(fb, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		i;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		if (open(argv[i], O_DIRECTORY) >= 0)
		{
			write(2, "Is a directory\n", 15);
			return (0);
		}
	}
	if ((fd = open(argv[i], O_RDONLY) < 0))
		ft_displayerror(argv[i]);
	else
		{
			ft_display(argc,argv);
		}
		i++;
		close (fd);
	}
	return (0);
}
