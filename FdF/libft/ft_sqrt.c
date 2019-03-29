/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:53:13 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 11:53:26 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int min;
	int max;
	int i;

	if (nb > 0)
	{
		min = 0;
		max = 46341;
		i = (min + max) / 2;
		while (max - min != 1)
		{
			if (i * i > nb)
				max = i;
			else if (i * i < nb)
				min = i;
			else if (i * i == nb)
				return (i);
			i = (min + max) / 2;
		}
	}
	return (0);
}
