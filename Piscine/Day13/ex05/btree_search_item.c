/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:39:10 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/02 20:48:33 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	if (!root)
		return (NULL);
	if (root->left)
		btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->right)
		btree_search_item(root->left, data_ref, cmpf);
}
