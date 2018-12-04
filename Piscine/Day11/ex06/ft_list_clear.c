/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:43:14 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 18:09:58 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*previous;

	while (*begin_list)
	{
		previous = *begin_list;
		*begin_list = (*begin_list)->next;
		free(previous);
	}
	*begin_list = NULL;
}
