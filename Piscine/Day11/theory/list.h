/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:29:54 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 18:19:26 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef struct s_list t_list;

struct	s_list
{
	char *str;
	t_list *next;
};

t_list *add_link(t_list *list, char *str);
void	print_list(t_list *list);

#endif
