/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolving_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:16:52 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/12 13:16:55 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

//	Возможные ходы:
//		1. reduce_the_distance() - ход, направленный на сокращение дистанции до оппонента.
//		2. attempt_to_surround() - ход, задача которого выставить фигуру максимально эффективным образом,
//			уменьшая количество доступных для оппонента точек
//		3. plow_the_land() - ход, выполняемый в случае если предыдущие два действия невозможны;
//			заполнение свободных полей фигурами, когда агрессивные действия не имеют смысла или невозможны

static void	check_surroundings(t_map *map, char **field, int i, int j)
{
	if (i > 0 && j > 0 && is_my_piece(map, (*map).field[i - 1][j - 1]))
		(*map).contact = 1;
	if (i > 0 && is_my_piece(map, (*map).field[i - 1][j]))
		(*map).contact = 1;
	if (i > 0 && j < (*map).width - 1
			&& is_my_piece(map, (*map).field[i - 1][j + 1]))
		(*map).contact = 1;
	if (j > 0 && is_my_piece(map, (*map).field[i][j - 1]))
		(*map).contact = 1;
	if (j < (*map).width && is_my_piece(map, (*map).field[i][j + 1]))
		(*map).contact = 1;
	if (i < (*map).height - 1)
	{
		if (j > 0 && is_my_piece(map, (*map).field[i + 1][j - 1]))
			(*map).contact = 1;
		if (is_my_piece(map, (*map).field[i + 1][j]))
			(*map).contact = 1;
		if (j < (*map).width - 1
				&& is_my_piece(map, (*map).field[i + 1][j + 1]))
			(*map).contact = 1;
	}
}

static void	check_contact(t_map *map, int width, int height)
{
	int i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((*map).field[i][j] == (*map).op_letter[0]
					|| (*map).field[i][j] == (*map).op_letter[1])
				check_surroundings(map, (*map).field, i, j);
			j++;
		}
		i++;
	}
}

void		place_token(t_map *map, int fd)
{
	if (!(*map).contact)
		check_contact(map, (*map).width, (*map).height);
	!(*map).contact ? reduce_the_distance(map) : attempt_to_surround(map);
}
