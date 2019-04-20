/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:42:15 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/19 15:42:22 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
