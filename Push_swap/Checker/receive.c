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

void	get_options(t_flag *options, char **av, int ac)
{
	options->verbose = 0;
	options->colored = 0;
	if (ac > 1)
	{
		options->verbose = ft_strequ(av[0], "-v") ? 1 : 0;
		options->colored = ft_strequ(av[0], "-c") ? 1 : 0;
		options->verbose = ft_strequ(av[0], "-vc")
				&& !options->verbose && !options->colored ? 1 : 0;
		options->colored = ft_strequ(av[0], "-vc")
				&& options->verbose && !options->colored ? 1 : 0;
		if (ac > 2)
		{
			options->verbose = ft_strequ(av[1], "-v")
					&& !options->verbose ? 1 : 0;
			options->colored = ft_strequ(av[1], "-c")
					&& !options->colored ? 1 : 0;
		}
	}
}

void	get_stack(t_list **stack_a, t_list **stack_b, char **av, int ac)
{
	int	num;
	int	i;

	*stack_a = NULL;
	*stack_b = NULL;
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

	*instr = NULL;
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
