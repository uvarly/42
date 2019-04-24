/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:56:31 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/24 15:56:32 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int		are_arguments_valid(char **av, int ac);

void	get_stack(t_list **stack, char **av, int ac);

void	apply_indexation(t_list *stack);

void	get_instructions_ascensional(t_list *stack, t_list **instr_asc);
void	get_instructions_ordinal(t_list *stack, t_list **instr_ord);

#endif
