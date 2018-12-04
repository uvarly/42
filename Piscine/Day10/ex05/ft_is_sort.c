/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:09:18 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 14:34:01 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int counter_asc;
	int counter_desc;

	i = 0;
	counter_asc = 0;
	counter_desc = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			counter_asc++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			counter_desc++;
	}
	if ((counter_asc == length - 1) || (counter_desc == length - 1))
		return (1);
	return (0);
}
