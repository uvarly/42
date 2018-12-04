/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:25:32 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/31 20:46:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list)
	{
		while (begin_list->next)
		{
			begin_list->data = f(begin_list->data);
			begin_list = begin_list->next;
		}
	}
}
