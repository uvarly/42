/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:55:33 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 19:57:33 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int		main(void)
{
	t_list *list;

	list = NULL;
	list = add_link(list, "nigga");
	list = add_link(list, ",");
	list = add_link(list, "back");
	list = add_link(list, "be");
	list = add_link(list, "I'll");
	print_list(list);
	return (0);
}
