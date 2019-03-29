/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:49:41 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 14:35:09 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if (*alst)
	{
		new = *alst;
		while (new->next)
			new = new->next;
		new->next = ft_lstnew(content, content_size);
	}
	else
		*alst = ft_lstnew(content, content_size);
}
