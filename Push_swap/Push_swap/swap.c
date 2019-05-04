/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:06 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/26 15:28:08 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*temp;

	if (*list)
	{
		temp = (*list)->next;
		if (temp)
		{
			(*list)->next = temp->next;
			temp->next = *list;
			*list = temp;
		}
	}
}

void	swap_s(t_list **list1, t_list **list2)
{
	swap(list1);
	swap(list2);
}
