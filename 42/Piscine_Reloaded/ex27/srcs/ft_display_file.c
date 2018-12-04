/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:18:33 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/27 12:20:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_headers.h"

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_error(int ac)
{
	if (ac == 1)
		write(2, "File name missing.", 18);
	if (ac > 2)
		write(2, "Too many arguments.", 19);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	if (argc != 2)
	{
		ft_print_error(argc);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
	return (0);
}
