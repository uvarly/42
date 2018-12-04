/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 22:31:39 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/25 22:53:39 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (factory[a])
	{
		while (factory[a][b])
		{
			free(factory[a][b]);
			b++;
		}
		free(factory[a]);
		a++;
	}
}
