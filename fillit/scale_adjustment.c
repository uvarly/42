/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_adjustment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:04:12 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:04:14 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_dangerous_figure(char **input)
{
	short	i;

	i = 0;
	while (input[i])
	{
		if (g_scale == 4 && input[i][0] == '#')
			if ((input[i][1] == '#'
				&& input[i][2] == '#'
				&& input[i][3] == '#')
			|| (input[i][4] == '#'
				&& input[i][8] == '#'
				&& input[i][12] == '#'))
				return (1);
		i++;
	}
	return (0);
}

static short	get_scale(char **input)
{
	short	scale;

	scale = 0;
	while (input[scale])
		scale++;
	scale *= 4;
	while (!ft_sqrt(scale))
		scale++;
	scale = ft_sqrt(scale);
	return (scale);
}

char			*increase_scale(char *object)
{
	char	*new_object;
	char	*temp;
	short	scale;
	short	len;
	short	i;

	scale = g_scale + 1;
	len = scale * scale;
	if (!(new_object = ft_strnew(len)))
		return (object);
	temp = object;
	i = 0;
	while (i < len - scale - 1)
	{
		if (i % scale == g_scale)
		{
			new_object[i] = '.';
			i++;
		}
		new_object[i++] = *(object++);
	}
	while (i < len)
		new_object[i++] = '.';
	free(temp);
	return (new_object);
}

char			*decrease_scale(char *object)
{
	char	*new_object;
	char	*temp;
	short	len;
	short	i;
	short	j;

	len = (g_scale - 1) * (g_scale - 1);
	if (!(new_object = ft_strnew(len)))
		return (object);
	temp = object;
	i = 0;
	j = 0;
	while (i < len)
	{
		if ((i + j) % g_scale == g_scale - 1)
			j++;
		new_object[i] = object[i + j];
		i++;
	}
	free(temp);
	return (new_object);
}

void			adjust_scale(char **input)
{
	short	scale;
	short	i;

	scale = get_scale(input);
	if (scale < g_scale && has_dangerous_figure(input))
		return ;
	while (scale != g_scale)
	{
		if (g_scale == 3)
			return ;
		i = 0;
		while (input[i])
		{
			input[i] = (scale > g_scale) ?
				increase_scale(input[i]) :
				decrease_scale(input[i]);
			i++;
		}
		(scale > g_scale) ?
			g_scale++ :
			g_scale--;
	}
}
