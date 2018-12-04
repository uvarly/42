/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:37:44 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/04 16:14:16 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		return (ft_putnbr(147483648));
	}
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
		ft_putnbr(num);
	}
	else
	{
		if (num / 10 > 0)
			ft_putnbr(num / 10);
		ft_putchar('0' + num % 10);
	}
}
