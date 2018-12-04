/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 15:37:05 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/21 15:37:13 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	outer_line(int length)
{
	int i;

	i = 1;
	while (i <= length)
	{
		if (i == 1 || i == length)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
	ft_putchar('\n');
}

void	middle_line(int length, int width)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= width - 2)
	{
		while (i <= length)
		{
			if (i == 1 || i == length)
				ft_putchar('|');
			else
				ft_putchar(' ');
			i++;
		}
		i = 1;
		j++;
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (y > 0 && x > 0)
		outer_line(x);
	if (y > 2 && x > 0)
		middle_line(x, y);
	if (y > 1 && x > 0)
		outer_line(x);
}
