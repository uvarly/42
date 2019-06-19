/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstintmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:17:12 by uvarly            #+#    #+#             */
/*   Updated: 2019/05/20 17:17:14 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstintmax(t_list *list)
{
	int	max;

	max = INT32_MIN;
	while (list)
	{
		if (max < *((int *)(list->content)))
			max = *((int *)(list->content));
		list = list->next;
	}
	return (max);
}
