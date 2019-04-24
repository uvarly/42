/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:56:28 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/24 15:56:29 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instr(t_list *instr)
{
	while (instr)
	{
		ft_putstr(instr->content);
		ft_putchar('\n');
		instr = instr->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*instr_asc;
	t_list	*instr_ord;

	get_stack(&stack, argv + 1, argc - 1);
	get_instructions_ascensional(stack, &instr_asc);
	get_instructions_ordinal(stack, &instr_ord);

	print_instr(ft_lstlen(instr_asc) < ft_lstlen(instr_ord) ?
			instr_asc : instr_ord);

	ft_lstfree(&stack);
	ft_lstfree(&instr_asc);
	ft_lstfree(&instr_ord);
	return (0);
}
