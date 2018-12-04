/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:22:38 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 19:03:46 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int	counter;

	counter = 0;
	while (counter < nbr && begin_list)
	{
		begin_list = begin_list->next;
		counter++;
	}
	return (begin_list);
}
