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

void	swap(t_list **list, t_list **instr, char which_stack)
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
	if (which_stack != 0)
		ft_lstappend(instr, which_stack == 'a' ? ft_lstnew("sa\n", 3) : ft_lstnew("sb\n", 3));
}

void	swap_s(t_list **list1, t_list **list2, t_list **instr)
{
	swap(list1, instr, 'a');
	swap(list2, instr, 'b');
	ft_lstappend(instr, ft_lstnew("ss\n", 3));
}
