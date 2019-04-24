/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/24 16:06:18 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(t_list **stack, char **av, int ac)
{
	int	num;
	int	i;

	*stack = NULL;
	if (are_arguments_valid(av, ac))
	{
		i = 0;
		while (i < ac)
		{
			num = ft_atoi(av[i]);
			ft_lstappend(stack, ft_lstnew(&num, sizeof(int)));
			i++;
		}
	}
	if (!*stack)
	{
		write(2, "Error\n", 6);
		ft_lstfree(stack);
		exit(0);
	}
	apply_indexation(*stack);
}
