/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:00:10 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/06 12:51:06 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new;
	t_list	*temp;

	new = 0;
	begin = new;
	while (lst)
	{
		temp = f(lst);
		new = ft_lstnew(temp->content, temp->content_size);
		if (!new)
			return (0);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
