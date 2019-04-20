/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:17:12 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/19 16:17:14 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_stack(t_list **stack_a, char **av, int ac)
{
	int	num;
	int	i;

	if (are_arguments_valid(av, ac))
	{
		i = 0;
		while (i < ac)
		{
			num = ft_atoi(av[i]);
			ft_lstappend(stack_a, ft_lstnew(&num, sizeof(int)));
			i++;
		}
	}
	if (!*stack_a)
	{
		write(2, "Error\n", 6);
		ft_lstfree(stack_a);
		exit(0);
	}
}

void	get_instr(t_list **instr)
{
	t_list	*temp;
	char	*line;

	while (get_next_line(0, &line))
	{
		temp = ft_lstnew(line, ft_strlen(line));
		ft_lstappend(instr, temp);
		if (!is_instruction_valid(temp->content))
		{
			free(line);
			ft_lstfree(instr);
			return ;
		}
		free(line);
	}
}
