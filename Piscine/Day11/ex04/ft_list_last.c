/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:22:34 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 18:12:18 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*last_elem;

	if (!begin_list)
		return (begin_list);
	last_elem = begin_list;
	while (last_elem->next)
		last_elem = last_elem->next;
	return (last_elem);
}
