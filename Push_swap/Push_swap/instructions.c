/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:29:14 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/26 14:29:15 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		copy_stack(t_list *stack, t_list **stack_a)
{
	*stack_a = NULL;
	while (stack)
	{
		ft_lstappend(stack_a, ft_lstnew(stack->content, sizeof(int)));
		stack = stack->next;
	}
}

static int	is_false_element(t_list *stack, int *true_elements, int count)
{
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (i < count)
	{
		if (*((int *)(stack->content)) == true_elements[i])
		{
			flag++;
			break ;
		}
		i++;
	}
	if (flag != 1)
		return (1);
	return (0);
}

static int	has_false_elements(t_list *stack, int *true_elements, int count)
{
	while (stack)
	{
		if (is_false_element(stack, true_elements, count))
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	is_swap_required(t_list *stack, t_list **instr, int count_prev, int order)
{
	t_list	*stack_a;
	int		*true_elements;
	int		count_curr;

	if (stack && stack->next)
	{
		copy_stack(stack, &stack_a);
		swap(&stack_a, instr, 0);
		count_curr = get_true_elements(stack_a, &true_elements, order);
		if (count_curr > count_prev)
		{
			ft_lstfree(&stack_a);
			free(true_elements);
			return (1);
		}
		ft_lstfree(&stack_a);
		free(true_elements);
	}
	return (0);
}

#include <stdio.h>

void		get_instructions(t_list *stack, t_list **instr, int order)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*true_elements;
	int		count;

	*instr = NULL;
	stack_b = NULL;
	copy_stack(stack, &stack_a);
	count = get_true_elements(stack_a, &true_elements, order);
	while (has_false_elements(stack_a, true_elements, count))
	{
		if (is_swap_required(stack_a, instr, count, order))
		{
			swap(&stack_a, instr, 'a');
			free(true_elements);
			count = get_true_elements(stack_a, &true_elements, order);
		}
		else if (is_false_element(stack_a, true_elements, count))
			push(&stack_b, &stack_a, instr, 'a');
		else
			rotate(&stack_a, instr, 'a');
	}
	while (stack_b)
		perform_quickest_push(stack_a, stack_b, instr);
	reset_stack(stack_a, instr);
	free(true_elements);
	ft_lstfree(&stack_a);
}
