/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_offset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:02:57 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:00 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	simple_offset(char *figure)
{
	short	i;
	short	count;

	i = 8;
	count = 4;
	while (figure[i] && count > 0)
	{
		if (figure[i] == '#')
		{
			figure[i] = '.';
			figure[i + g_scale] = '#';
			count--;
		}
		i--;
	}
}

static int is_last_column_empty(char *figure)
{
	if (figure[2] == '.' && figure[5] == '.' && figure[8] == '.')
		return (1);
	return (0);
}

int			offset_figure(char *figure)
{
	char	prev;
	char	curr;
	short	i;

	if (!is_able_to_offset_furhter(figure))
	{
		reset_figure(figure);
		return (0);
	}
	if (g_scale == 3 && !is_last_column_empty(figure))
	{
		simple_offset(figure);
		return (1);
	}
	prev = '.';
	i = 0;
	while (figure[i])
	{
		curr = figure[i];
		figure[i] = prev;
		prev = curr;
		i++;
	}
	return (is_figure_valid(figure) ? 1 : offset_figure(figure));
}

int			is_able_to_offset_furhter(char *figure)
{
	short	len;

	len = g_scale * g_scale;
	if (figure[len - 1] == '#'
		|| (figure[len - g_scale - 1] == '#'
			&& figure[len - g_scale - 2] == '#'
			&& figure[len - 3] == '#' && figure[len - 2] == '#')
		|| (figure[len - g_scale - 3] == '#'
			&& figure[len - g_scale - 2] == '#'
			&& figure[len - g_scale - 1] == '#' && figure[len - 3] == '#')
		|| (figure[len - 2 * g_scale - 2] == '#'
			&& figure[len - 2 * g_scale - 1] == '#'
			&& figure[len - g_scale - 2] == '#' && figure[len - 2] == '#')
		|| (figure[len - 2 * g_scale - 1] == '#'
			&& figure[len - g_scale - 2] == '#'
			&& figure[len - g_scale - 1] == '#' && figure[len - 2] == '#')
		|| (figure[len - 2 * g_scale - 2] == '#'
			&& figure[len - g_scale - 2] == '#'
			&& figure[len - g_scale - 1] == '#' && figure[len - 2] == '#')
		|| (figure[len - g_scale - 3] == '#'
			&& figure[len - g_scale - 2] == '#'
			&& figure[len - g_scale - 1] == '#' && figure[len - 2] == '#'))
		return (0);
	return (1);
}
