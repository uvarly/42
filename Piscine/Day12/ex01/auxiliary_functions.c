/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:13:20 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/01 19:49:24 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

void	ft_putstr(char *string)
{
	unsigned int i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}

int		ft_strlen(char *string)
{
	unsigned int i;

	i = 0;
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}
