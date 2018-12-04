/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:53:09 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/25 12:31:55 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_fill_array(int *arr, int min, int max)
{
	unsigned int i;
	unsigned int range;

	i = 0;
	range = max - min;
	while (i < range)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int		*ft_range(int min, int max)
{
	int	*int_array;

	if (min >= max)
		return (0);
	int_array = (int*)malloc((sizeof(int)) * (max - min));
	if (int_array)
		return (ft_fill_array(int_array, min, max));
	return (int_array);
}
