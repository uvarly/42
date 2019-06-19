/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:29:23 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/24 16:29:24 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_list *stack, int *array, size_t len)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		array[i] = *((int *)(stack->content));
		stack = stack->next;
		i++;
	}
	ft_sortinttab(array, len);
}

static void	get_corresponding_value(int *content, int *array)
{
	size_t	i;

	i = 0;
	while (*content != array[i])
		i++;
	*content = i;
}

void		apply_indexation(t_list *stack)
{
	size_t	len;
	int		*array;

	len = ft_lstlen(stack);
	array = ft_memalloc(sizeof(int) * len);
	fill_array(stack, array, len);
	while (stack)
	{
		get_corresponding_value((int *)(stack->content), array);
		stack = stack->next;
	}
	ft_memdel((void **)&(array));
}
