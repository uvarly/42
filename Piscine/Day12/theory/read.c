/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:38:46 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/01 12:54:25 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_lib.h"

#define BUF_SIZE 5

int		main(void)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buf);
	}
	buf[ret] = '\0';
	ft_putstr("\n");
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
