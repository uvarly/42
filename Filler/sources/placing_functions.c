/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:43:17 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/15 11:43:19 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	is_compatible(t_map *map, char *map_line, char *token_line)
{
	int	intersection;

	intersection = 0;
	while (*token_line)
	{

		map_line++;
		token_line++;
	}
	return (1);
}

static int	is_able_to_place(t_map *map, int i, int j)
{
	char	*map_line;
	char	*token_line;
	int		k;

	if ((*map).token.height + i > (*map).height
			|| (*map).token.width + j > (*map).width)
		return (0);
	k = 0;
	while (k < (*map).token.height)
	{
		map_line = *((*map).field + k);
		token_line = *((*map).token.shape + k);
		if (!is_compatible(map, map_line, token_line))
			return (0);
		k++;
	}
	return (1);
}

void		reduce_the_distance(t_map *map)
{
	unsigned int	dist;
	unsigned int	temp_dist;
	int				i;
	int				j;

	dist = -1;
	i = -1;
	while (++i < (*map).height)
	{
		j = -1;
		while (++j < (*map).width)
			if (is_able_to_place(map, i, j))
			{
				temp_dist = evaluate_distance(map, i, j);
				if (temp_dist < dist)
				{
					dist = temp_dist;
					(*map).token.x = j;
					(*map).token.y = i;
				}
			}
	}
}
