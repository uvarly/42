/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:10:17 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/29 17:50:40 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	i = 0;
	result = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		*result = f(tab[i]);
		i++;
	}
	return (result);
}
