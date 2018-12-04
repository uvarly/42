/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:01:40 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 17:40:25 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;

	if (*begin_list)
	{
		new_list = ft_create_elem(data);
		new_list->next = *begin_list;
		*begin_list = new_list;
	}
	else
		*begin_list = ft_create_elem(data);
}
