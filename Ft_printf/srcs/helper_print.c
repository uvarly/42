/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:02:52 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 18:58:02 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_ubase(unsigned long long num, unsigned int base, int uppercase)
{
	if (num > base - 1)
		put_ubase(num / base, base, uppercase);
	if (uppercase == 0)
		ft_putchar((num % base) > 9 ? (num % base) + 'a' - 10 :
								(num % base) + '0');
	else
		ft_putchar((num % base) > 9 ? (num % base) + 'A' - 10 :
								(num % base) + '0');
}

void	put_base(long long num, int base)
{
	if (num < -(base - 1) || num > base - 1)
		put_base(num < 0 ? ((num / base) * -1) : num / base, base);
	if (num % base > 9 || num % base < -9)
		ft_putchar((num % base) < 0
			? (num % base) * -1 + 'a' - 10 : num % base + 'a' - 10);
	else
		ft_putchar((num % base) < 0
			? (num % base) * -1 + '0' : num % base + '0');
}

void	putnchr(char c, int amount)
{
	char	str[amount];
	int		i;

	i = 0;
	while (i < amount)
	{
		str[i] = c;
		i++;
	}
	write(1, str, amount);
}

void	print_float(char *num)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 8)
		{
			ft_putchar((num[9 - i] >> (7 - j) & 1) + '0');
			j++;
		}
		if (i != 9)
			ft_putchar(' ');
		j = 0;
		i++;
	}
}
