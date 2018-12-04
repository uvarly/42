/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 10:29:47 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/01 11:29:17 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *string)
{
	while (*string)
		write(1, string++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar(1, '-');
		ft_putchar(1, '2');
		return (ft_putnbr(147483648));
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar(1, '-');
	}
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar(1, '0' + nb % 10);
}

int		ft_strlen(char *string)
{
	unsigned int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
