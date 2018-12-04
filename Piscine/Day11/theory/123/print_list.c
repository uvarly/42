/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:03:54 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 20:02:37 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "list.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar(char *string)
{
	while(*string)
	{
		ft_putchar(*string);
		string++;
	}
}

void print_list(t_lits *char)
{
	while (list)
	{
		ft_putstr(list -> str);
		list = list -> next;
	}
}
