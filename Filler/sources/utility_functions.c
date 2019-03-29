/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:17:05 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/12 13:17:06 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initialize_structure(t_map *map)
{
	(*map).width = 0;
	(*map).height = 0;
	(*map).initial_turn = 0;
	(*map).my_letter[0] = 0;
	(*map).my_letter[1] = 0;
	(*map).op_letter[0] = 0;
	(*map).op_letter[1] = 0;
	(*map).contact = 0;
	(*map).field = NULL;
	(*map).token.width = 0;
	(*map).token.width = 0;
	(*map).token.x = 0;
	(*map).token.y = 0;
	(*map).token.shape = NULL;
}

void	get_new_line(char **line)
{
	char	buf[2];
	char	*temp;
	int		ret;

	(ret = read(0, buf, 1)) != 1 ? exit(0) : 0;
	*line = NULL;
	while (ft_strchr(buf, '\n') == NULL)
	{
		buf[1] = 0;
		temp = *line;
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
		*line == NULL ? exit(0) : 0;
		free(temp);
		(ret = read(0, buf, 1)) != 1 ? exit(0) : 0;
	}
}

void	destroy_object(char ***object, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		ft_strclr((*object)[i]);
		free((*object)[i]);
		(*object)[i] = NULL;
		i++;
	}
	free(*object);
}

void	allocate_object(char ***object, int height)
{
	int	i;

	i = 0;
	(*object = (char **)malloc(sizeof(char *) * height)) == NULL ? exit(0) : 0;
	while (i < height)
	{
		(*object)[i] = NULL;
		i++;
	}
}

int		is_my_piece(t_map *map, char piece)
{
	if (piece == (*map).my_letter[0] || piece == (*map).my_letter[1])
		return (1);
	return (0);
}
