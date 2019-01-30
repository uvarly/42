/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:21 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	check_surroundings(char *figure, short i)
{
	short	len;
	short	adjacent_blocks;

	len = g_scale * g_scale;
	adjacent_blocks = 0;
	if (i - g_scale >= 0 && figure[i - g_scale] == '#')
		adjacent_blocks++;
	if (i % g_scale != 0 && figure[i - 1] == '#')
		adjacent_blocks++;
	if (i % g_scale != g_scale - 1 && figure[i + 1] == '#')
		adjacent_blocks++;
	if (i + g_scale < len && figure[i + g_scale] == '#')
		adjacent_blocks++;
	return (adjacent_blocks);
}

static int		correct_amount_of_blocks(char *figure)
{
	short	count;

	count = 0;
	while (*figure)
	{
		if (*figure == '#')
			count++;
		figure++;
	}
	return (count == 4 ? 1 : 0);
}

int				is_figure_valid(char *figure)
{
	short	i;
	short	adjacent_blocks;
	short	blocks_with_two_neighbours;
	short	len;

	i = 0;
	blocks_with_two_neighbours = 0;
	len = g_scale * g_scale;
	while (i < len)
	{
		if (figure[i] == '#')
		{
			adjacent_blocks = check_surroundings(figure, i);
			if (adjacent_blocks == 0)
				return (0);
			if (adjacent_blocks > 1)
				blocks_with_two_neighbours++;
		}
		i++;
	}
	return (blocks_with_two_neighbours > 0 &&
			correct_amount_of_blocks(figure) ? 1 : 0);
}
