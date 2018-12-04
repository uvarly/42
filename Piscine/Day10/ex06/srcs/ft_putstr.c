/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:07:56 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 12:46:43 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	ft_putstr(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		ft_putchar(string[i]);
		i++;
	}
}
