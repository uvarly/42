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

void	rotate(t_list **list, t_list **instr, char which_stack)
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
		ft_lstappend(instr, which_stack == 'a' ? ft_lstnew("ra\n", 3) : ft_lstnew("rb\n", 3));
	}
}

void	rotate_r(t_list **list1, t_list **list2, t_list **instr)
{
	rotate(list1, instr, 'a');
	rotate(list2, instr, 'b');
	ft_lstappend(instr, ft_lstnew("rr\n", 3));
}

void	rrotate(t_list **list, t_list **instr, char which_stack)
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
		ft_lstappend(instr, which_stack == 'a' ? ft_lstnew("rra\n", 4) : ft_lstnew("rrb\n", 4));
	}
}

void	rrotate_r(t_list **list1, t_list **list2, t_list **instr)
{
	rrotate(list1, instr, 'a');
	rrotate(list2, instr, 'b');
}
