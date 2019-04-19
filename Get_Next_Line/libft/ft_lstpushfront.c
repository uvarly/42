/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:51:46 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 12:32:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if (*alst)
	{
		new = ft_lstnew(content, content_size);
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = ft_lstnew(content, content_size);
}
