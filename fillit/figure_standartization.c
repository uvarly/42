/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_standartization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:14 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:16 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char	*standartize_figure(char *figure)
{
	char	*dest;
	char	*temp;

	if (!(temp = (char *)malloc(sizeof(char) * (strlen(figure) - 4 + 1))))
		return (0);
	dest = temp;
	while (*figure)
	{
		if (*figure == '\n')
			figure++;
		*temp = *figure;
		temp++;
		figure++;
	}
	*temp = 0;
	if (!is_figure_valid(dest))
		return (0);
	reset_figure(dest);
	return (dest);
}

int			standartize_input(char ***input)
{
	char	*temp;
	short	i;

	if (!**input)
		return (0);
	i = 0;
	while ((*input)[i])
	{
		if ((*input)[i][4] != '\n' || (*input)[i][9] != '\n'
		|| (*input)[i][14] != '\n' || (*input)[i][19] != '\n')
			return (0);
		if (!(temp = standartize_figure((*input)[i])))
			return (0);
		free((*input)[i]);
		(*input)[i] = temp;
		i++;
	}
	return (1);
}
