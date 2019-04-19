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

#include "../includes/checker.h"

void	swap(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *list;
	tmp2 = (*list)->next;
	if (tmp1 && tmp2)
	{
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*list = tmp2;
	}
}

void	swap_s(t_list **list1, t_list **list2)
{
	swap(list1);
	swap(list2);
}
