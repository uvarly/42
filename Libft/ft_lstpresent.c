/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpresent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:03:46 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/19 16:03:48 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpresent(t_list *list, char *str)
{
	while (list)
	{
		if (ft_strequ(list->content, str))
			return (1);
		list = list->next;
	}
	return (0);
}
