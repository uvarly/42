/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:33:38 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 17:59:12 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int		main(void)
{
	t_list *list;

	list = NULL;
	list = add_link(list, "0000\n");
	list = add_link(list, "0001\n");
	list = add_link(list, "0002\n");
	list = add_link(list, "0003\n");
	list = add_link(list, "0004\n");
	list = add_link(list, "0005\n");

	print_list(list);
	return (0);
}
