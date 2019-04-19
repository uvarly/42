/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortinttab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:42:59 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/14 15:28:48 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortinttab(int *table, size_t n)
{
	int		temp;
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		if (table[i] > table[i + 1])
		{
			temp = table[i];
			table[i] = table[i + 1];
			table[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
