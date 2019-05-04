/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:54:12 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/26 11:54:14 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_head_value(t_list *stack, int order)
{
	int	elem;
	int	value;

	elem = *((int *)(stack->content));
	value = 1;
	while (stack)
	{
		if (order == 0)
			if (elem < *((int *)(stack->content)))
			{
				elem = *((int *)(stack->content));
				value++;
			}
		if (order == 1)
		{
			if (elem == *((int *)(stack->content)) - 1)
			{
				elem = *((int *)(stack->content));
				value++;
			}
		}
		stack = stack->next;
	}
	return (value);
}

static void		fill_true_elements_array(int *true_elements,
		t_list *stack, int head_index, int order)
{
	size_t	i;

	while (*((int *)(stack->content)) != head_index)
		stack = stack->next;
	true_elements[0] = head_index;
	i = 1;
	while (stack)
	{
		if (order == 0)
			if (head_index < *((int *)(stack->content)))
			{
				true_elements[i] = *((int *)(stack->content));
				head_index = *((int *)(stack->content));
				i++;
			}
		if (order == 1)
			if (head_index == *((int *)(stack->content)) - 1)
			{
				true_elements[i] = *((int *)(stack->content));
				head_index = *((int *)(stack->content));
				i++;
			}
		stack = stack->next;
	}
}

int				get_true_elements(t_list *stack, int **true_elements, int order)
{
	t_list	*begin;
	int		head_value;
	int		head_index;
	int		temp;

	*true_elements = NULL;
	begin = stack;
	head_value = 0;
	head_index = 0;
	while (stack)
	{
		temp = get_head_value(stack, order);
		if (head_value < temp)
		{
			head_value = temp;
			head_index = *((int *)(stack->content));
		}
		stack = stack->next;
	}
	*true_elements = ft_memalloc(sizeof(int) * head_value);
	fill_true_elements_array(*true_elements,
			begin, head_index, order);
	return (head_value);
}
