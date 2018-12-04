/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:11:07 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 20:37:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_list;

	if (*begin_list)
	{
		new_list = *begin_list;
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
