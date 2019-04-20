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

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putchar('(');
		ft_putnbr(*((int *)(list->content)));
		ft_putchar(')');
		ft_putstr("->");
		list = list->next;
	}
	ft_putstr("NULL\n");
}

void	perform_instructions(t_list **stack_a, t_list **stack_b, t_list *instr)
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
		instr = instr->next;
	}
}

int		is_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	int	temp;

	if (stack_a || !stack_b)
		return (0);
	temp = *((int *)(stack_b->content));
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (temp < *((int *)(stack_b->content)))
			return (0);
		temp = *((int *)(stack_b->content));
		stack_b = stack_b->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instr;

	stack_a = NULL;
	stack_b = NULL;
	instr = NULL;
	get_stack(&stack_a, argv + 1, argc - 1);
	get_instr(&instr);
	if (argc < 2 || !stack_a || !instr)
	{
		write(2, "Error\n", 6);
		ft_lstfree(&stack_a);
		ft_lstfree(&stack_b);
		ft_lstfree(&instr);
		return (0);
	}
	perform_instructions(&stack_a, &stack_b, instr);
	is_stack_sorted(stack_a, stack_b) ?
			write(1, "OK\n", 3) : write(1, "KO\n", 3);
	ft_lstfree(&stack_a);
	ft_lstfree(&stack_b);
	ft_lstfree(&instr);
	return (0);
}
