/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:48:53 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/17 16:48:55 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

static void	perform_instructions(t_list **stack_a, t_list **stack_b, t_list *instr)
{
	while (instr)
	{
		ft_strequ(instr->content, "sa") ? swap(stack_a) : NULL;
		ft_strequ(instr->content, "sb") ? swap(stack_b) : NULL;
		ft_strequ(instr->content, "ss") ? swap_s(stack_a, stack_b) : NULL;
		// ft_strequ(instr->content, "pa") ? push_a() : NULL;
		// ft_strequ(instr->content, "pb") ? push_b() : NULL;
		// ft_strequ(instr->content, "ra") ? rotate_a() : NULL;
		// ft_strequ(instr->content, "rb") ? rotate_b() : NULL;
		// ft_strequ(instr->content, "rr") ? rotate_r() : NULL;
		// ft_strequ(instr->content, "rra") ? rrotate_a() : NULL;
		// ft_strequ(instr->content, "rrb") ? rrotate_b() : NULL;
		// ft_strequ(instr->content, "rrr") ? rrotate_r() : NULL;
		instr = instr->next;
	}
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instr;

	stack_a = NULL;
	stack_b = NULL;
	instr = NULL;
	get_stack(&stack_a, &stack_b, argv + 1, argc - 1);
	get_instr(&instr);
	if (argc < 2 || !stack_a || !stack_b || !instr)
	{
		write(2, "Error\n", 6);
		ft_lstfree(&stack_a);
		ft_lstfree(&stack_b);
		ft_lstfree(&instr);
		return (0);
	}
	perform_instructions(&stack_a, &stack_b, instr);
	ft_lstfree(&stack_a);
	ft_lstfree(&stack_b);
	ft_lstfree(&instr);
	return (0);
}
