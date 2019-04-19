/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:36:09 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 17:58:35 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	if (!content)
	{
		new_list->content = 0;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(sizeof(new_list->content) * content_size);
		if (!(new_list->content))
			return (0);
		new_list->content = ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = 0;
	return (new_list);
}
