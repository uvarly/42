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

#include "checker.h"
#include <stdio.h>

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("[%2d]", *(int *)(stack_a->content));
			// ft_putnbr(*(int *)(stack_a->content));
			stack_a = stack_a->next;
		}
		printf("\t");
		// ft_putstr("\t");
		if (stack_b)
		{
			printf("[%2d]", *(int *)(stack_b->content));
			// ft_putnbr(*(int *)(stack_b->content));
			stack_b = stack_b->next;
		}
		printf("\n");
		// ft_putchar('\n');
	}
	printf("\n");
	// ft_putchar('\n');
}

void	perform_instructions(t_list **stack_a, t_list **stack_b,
		t_list *instr)
{
	while (instr)
	{
		ft_strequ(instr->content, "sa") ? swap(stack_a) : NULL;
		ft_strequ(instr->content, "sb") ? swap(stack_b) : NULL;
		ft_strequ(instr->content, "ss") ? swap_s(stack_a, stack_b) : NULL;
		ft_strequ(instr->content, "pa") ? push(stack_a, stack_b) : NULL;
		ft_strequ(instr->content, "pb") ? push(stack_b, stack_a) : NULL;
		ft_strequ(instr->content, "ra") ? rotate(stack_a) : NULL;
		ft_strequ(instr->content, "rb") ? rotate(stack_b) : NULL;
		ft_strequ(instr->content, "rr") ? rotate_r(stack_a, stack_b) : NULL;
		ft_strequ(instr->content, "rra") ? rrotate(stack_a) : NULL;
		ft_strequ(instr->content, "rrb") ? rrotate(stack_b) : NULL;
		ft_strequ(instr->content, "rrr") ? rrotate_r(stack_a, stack_b) : NULL;
		print_stacks(*stack_a, *stack_b);
		instr = instr->next;
	}
}

int		is_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	int	temp;

	if (!stack_a || stack_b)
		return (0);
	temp = *((int *)(stack_a->content));
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (temp > *((int *)(stack_a->content)))
			return (0);
		temp = *((int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instr;

	get_stack(&stack_a, &stack_b, argv + 1, argc - 1);
	get_instr(&instr);
	if (argc < 2 || !stack_a)
	{
		write(2, "Error\n", 6);
		ft_lstfree(&stack_a);
		ft_lstfree(&stack_b);
		ft_lstfree(&instr);
		return (0);
	}
	print_stacks(stack_a, stack_b);
	perform_instructions(&stack_a, &stack_b, instr);
	is_stack_sorted(stack_a, stack_b) ?
			write(1, "OK\n", 3) : write(1, "KO\n", 3);
	ft_lstfree(&stack_a);
	ft_lstfree(&stack_b);
	ft_lstfree(&instr);
	return (0);
}
