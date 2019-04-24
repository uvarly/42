/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:11 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/24 16:06:12 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
