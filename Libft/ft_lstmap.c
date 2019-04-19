/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:00:10 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/14 14:43:16 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*begin;

	if (!lst || !f)
		return (0);
	temp = f(lst);
	if (!(begin = ft_lstnew(temp->content, temp->content_size)))
	{
		ft_lstfree(&begin);
		return (0);
	}
	begin = temp;
	lst = lst->next;
	while (lst)
	{
		if (!(temp->next = f(ft_lstnew(lst->content, lst->content_size))))
		{
			ft_lstfree(&begin);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (begin);
}
