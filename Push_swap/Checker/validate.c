/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/17 17:19:37 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	are_arguments_valid(char **av, int ac)
{
	t_list	*list;

	if (ac == 0)
		return (0);
	list = NULL;
	while (ac > 0)
	{
		if (!ft_isint(av[ac - 1]) || ft_lstpresent(list, av[ac - 1]))
		{
			ft_lstfree(&list);
			return (0);
		}
		ft_lstappend(&list, ft_lstnew(av[ac - 1], ft_strlen(av[ac - 1])));
		ac--;
	}
	ft_lstfree(&list);
	return (1);
}

int	is_instruction_valid(char *instr)
{
	if (ft_strequ(instr, "sa")
			|| ft_strequ(instr, "sb")
			|| ft_strequ(instr, "ss")
			|| ft_strequ(instr, "pa")
			|| ft_strequ(instr, "pb")
			|| ft_strequ(instr, "ra")
			|| ft_strequ(instr, "rb")
			|| ft_strequ(instr, "rr")
			|| ft_strequ(instr, "rra")
			|| ft_strequ(instr, "rrb")
			|| ft_strequ(instr, "rrr"))
		return (1);
	return (0);
}
