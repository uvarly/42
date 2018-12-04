/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 13:46:11 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/21 14:38:22 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	outer_line(int length, int indent)
{
	int i;

	i = 1;
	while (i <= length)
	{
		if (i == 1 || i == length)
			ft_putchar('A' + indent);
		else
			ft_putchar('B');
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
				ft_putchar('B');
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
	if (y > 0 && x != 0)
		outer_line(x, 0);
	if (y > 2 && x != 0)
		middle_line(x, y);
	if (y > 1 && x != 0)
		outer_line(x, 2);
}
