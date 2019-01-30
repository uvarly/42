/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:43 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:45 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	will_figure_fit(char *map, char *figure)
{
	short	i;

	i = 0;
	while (map[i] == '.' || (map[i] != '.' && figure[i] == '.'))
		i++;
	if (!map[i])
		return (1);
	while (offset_figure(figure))
	{
		i = 0;
		while (map[i] == '.' || (map[i] != '.' && figure[i] == '.'))
			i++;
		if (!map[i])
			return (1);
	}
	reset_figure(figure);
	return (0);
}

static void	place_figure(char *map, char *figure, char letter)
{
	short remaining_blocks;

	remaining_blocks = 4;
	while (remaining_blocks > 0 && *map)
	{
		if (*figure == '#')
		{
			*map = letter;
			remaining_blocks--;
		}
		map++;
		figure++;
	}
}

static void	erase_figure(char *map, char letter)
{
	while (*map)
	{
		if (*map == letter)
			*map = '.';
		map++;
	}
}

int			fill_map(char *map, char **figure, char letter)
{
	short	i;

	i = 0;
	while (figure[i])
	{
		if (will_figure_fit(map, figure[i]))
			place_figure(map, figure[i], letter + i);
		else
		{
			i--;
			erase_figure(map, letter + i);
			if (i == 0 && !is_able_to_offset_furhter(figure[0]))
				return (0);
			while (!offset_figure(figure[i]))
			{
				i--;
				erase_figure(map, letter + i);
				if (i == 0 && !is_able_to_offset_furhter(figure[0]))
					return (0);
			}
			i--;
		}
		i++;
	}
	return (1);
}
