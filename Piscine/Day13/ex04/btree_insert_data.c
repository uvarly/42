/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:15:49 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/02 20:36:26 by uvarly           ###   ########.fr       */
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

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	t_btree *new_element;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	new_element = *root;
	if ((cmpf(new_element->item, (*root)->item)) < 0 && (*root)->left)
		btree_insert_data(&((root)->left), item, cmpf);
	if ((cmpf(new_element->item, (*root)->item)) >= 0 && (*root)->right)
		btree_insert_data(&((root)->right), item, cmpf);
}
