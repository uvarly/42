/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:05 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:07 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_first_row_empty(char *figure)
{
	short	i;

	i = 0;
	while (i < g_scale)
	{
		if (figure[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int	is_first_column_empty(char *figure)
{
	short	i;

	i = 0;
	while (figure[i])
	{
		if (i % g_scale == 0 && figure[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	move_figure_up(char *figure)
{
	short	i;
	short	j;

	i = 0;
	j = 4;
	while (j > 0)
	{
		if (figure[i] == '#')
		{
			figure[i] = '.';
			figure[i - g_scale] = '#';
			j--;
		}
		i++;
	}
}

static void	move_figure_left(char *figure)
{
	short	i;
	short	j;

	i = 0;
	j = 4;
	while (j > 0)
	{
		if (figure[i] == '#')
		{
			figure[i] = '.';
			figure[i - 1] = '#';
			j--;
		}
		i++;
	}
}

void		reset_figure(char *figure)
{
	while (is_first_row_empty(figure))
		move_figure_up(figure);
	while (is_first_column_empty(figure))
		move_figure_left(figure);
}
