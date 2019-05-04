/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:25 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/26 15:28:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	if (*list && (*list)->next)
	{
		first = *list;
		*list = (*list)->next;
		first->next = NULL;
		last = *list;
		while (last->next)
			last = last->next;
		last->next = first;
	}
}

void	rotate_r(t_list **list1, t_list **list2)
{
	rotate(list1);
	rotate(list2);
}

void	rrotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (*list && (*list)->next)
	{
		second_last = *list;
		while ((second_last->next)->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		last->next = *list;
		*list = last;
	}
}

void	rrotate_r(t_list **list1, t_list **list2)
{
	rrotate(list1);
	rrotate(list2);
}
