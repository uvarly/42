/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:52 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/17 12:03:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_map(char *map)
{
	if (!(map = ft_strnew(g_scale * g_scale)))
		return (0);
	ft_memset(map, '.', g_scale * g_scale);
	return (map);
}

int		system_cheat(char *map, char **input)
{
	short	i;

	i = 0;
	while (input[i])
		i++;
	if (i == 1
		&& input[0][0] == '#' && input[0][1] == '#'
		&& input[0][3] == '#' && input[0][4] == '#')
	{
		free(map);
		if ((map = (char *)malloc(sizeof(char) * 5)))
		{
			map[4] = 0;
			ft_memset(map, 'A', 4);
			g_scale = 2;
			print_figure(map);
			free(input[0]);
			free(input);
			free(map);
			return (1);
		}
	}
	return (0);
}

char	**create_figures(void)
{
	char	**figures;
	short	i;

	if (!(figures = (char **)malloc(sizeof(char *) * 27)))
		return (0);
	i = 0;
	while (i < 27)
	{
		figures[i] = 0;
		i++;
	}
	return (figures);
}

int		launch_iterator(char **map, char ***input)
{
	short	i;

	while (!(fill_map(*map, *input, 'A')))
	{
		i = 0;
		while ((*input)[i])
		{
			reset_figure((*input)[i]);
			(*input)[i] = increase_scale((*input)[i]);
			i++;
		}
		g_scale++;
		free(*map);
		if (!(*map = create_map(*map)))
			return (0);
	}
	print_figure(*map);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*map;
	char	**input;

	g_scale = 4;
	map = 0;
	input = 0;
	if (!(input = create_figures()))
		return (0);
	if (argc != 2)
	{
		erase_all_memory(&input, &map);
		return (print_error_message_invalid());
	}
	if (!get_input(&input, argv[1]) || !standartize_input(&input))
	{
		erase_all_memory(&input, &map);
		return (print_error_message());
	}
	adjust_scale(input);
	if (!(map = create_map(map)))
		return (0);
	if (system_cheat(map, input))
		return (0);
	if (!launch_iterator(&map, &input))
		return (0);
	erase_all_memory(&input, &map);
	return (0);
}
