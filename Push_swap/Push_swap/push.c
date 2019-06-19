/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:17 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/26 15:28:19 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dst, t_list **src, t_list **instr, char which_stack)
{
	t_list	*temp;

	if (*src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
	ft_lstappend(instr, which_stack == 'a' ? ft_lstnew("pa\n", 3) : ft_lstnew("pb\n", 3));
}
