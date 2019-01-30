/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:03:19 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/23 16:03:21 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_figure(char *figure)
{
	short	len;
	short	i;

	len = strlen(figure);
	i = 0;
	while (figure[i])
	{
		if (i != 0 && i % g_scale == 0)
			write(1, "\n", 1);
		write(1, &figure[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		print_error_message(void)
{
	write(1, "error\n", 7);
	return (0);
}

int		print_error_message_invalid(void)
{
	write(1, "usage: fillit file\n", 20);
	return (0);
}

void	erase_all_memory(char ***input, char **map)
{
	int	i;

	i = 0;
	while ((*input)[i])
	{
		if ((*input)[i])
			free((*input)[i]);
		(*input)[i] = 0;
		i++;
	}
	free(*input);
	if (*map)
		free(*map);
	*input = 0;
	*map = 0;
}
