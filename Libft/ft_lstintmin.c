/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstintmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:17:22 by uvarly            #+#    #+#             */
/*   Updated: 2019/05/20 17:17:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstintmin(t_list *list)
{
	int	min;

	min = INT32_MAX;
	while (list)
	{
		if (min < *((int *)(list->content)))
			min = *((int *)(list->content));
		list = list->next;
	}
	return (min);
}
