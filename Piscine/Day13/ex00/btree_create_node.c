/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:44:07 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/02 19:32:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_element;

	if ((new_element = (t_btree *)malloc(sizeof(t_btree))))
	{
		new_element->left = NULL;
		new_element->right = NULL;
		new_element->item = item;
	}
	return (new_element);
}
