/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:23:03 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/26 05:43:54 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int i;
	int j;
	int *array;
	int new_length;

	i = 0;
	j = 0;
	while (i < length)
	{
		if (tab[i])
		{
			array[j] = tab[i];
			j++;
		}
		i++;
	}
	i = 0;
	while (array[i])
		i++;
	return (i);
}
