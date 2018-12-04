/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:58:31 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 19:56:42 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIST_H
#define	LIST_H

typedef	struct s_list	t_list;

struct	s_list
{
	char *string;
	t_list *next;
};

t_list	*add_link(t_list *list, char string);
void	print_list(t_list *list);

#endif
