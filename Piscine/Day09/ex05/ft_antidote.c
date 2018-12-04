/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:26:35 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/25 21:35:19 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if (((j > i) && (j < k)) || ((j < i) && (j > k)))
		return (j);
	if (((i > j) && (i < k)) || ((i < j) && (j > k)))
		return (i);
	if (((k > i) && (k < j)) || ((k < i) && (k > j)))
		return (k);
	return (0);
}
