/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:16:59 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/12 13:17:00 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	determine_move_order(t_map *map, int fd)
{
	char	*line;

	get_new_line(&line);
	(*map).initial_turn = ft_strstr(line, "p1") ? 1 : 2;
	(*map).my_letter[0] = (*map).initial_turn == 1 ? 'O' : 'X';
	(*map).my_letter[1] = (*map).initial_turn == 1 ? 'o' : 'x';
	(*map).op_letter[0] = (*map).initial_turn == 1 ? 'X' : 'O';
	(*map).op_letter[1] = (*map).initial_turn == 1 ? 'x' : 'o';
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	free(line);
}

void	determine_map_size(t_map *map, int fd)
{
	char	*line;

	get_new_line(&line);
	(*map).height = ft_atoi(ft_strchr(line, ' '));
	(*map).width = ft_atoi(ft_strrchr(line, ' '));
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	free(line);
}

void	determine_field(t_map *map, int fd)
{
	char	*line;
	int		i;

	((*map).field) ? destroy_object(&((*map).field), (*map).height) : 0;
	allocate_object(&((*map).field), (*map).height);
	get_new_line(&line);
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	free(line);
	i = 0;
	while (i < (*map).height)
	{
		get_new_line(&line);
		((*map).field[i] = ft_strdup(ft_strchr(line, ' ') + 1)) == NULL ?
				exit(0) : 0;
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
		i++;
	}
}

void	determine_token_size(t_map *map, int fd)
{
	char	*line;

	get_new_line(&line);
	(*map).token.height = ft_atoi(ft_strchr(line, ' '));
	(*map).token.width = ft_atoi(ft_strrchr(line, ' '));
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	free(line);
}

void	determine_token(t_map *map, int fd)
{
	char	*line;
	int		i;

	((*map).token.shape) ?
			destroy_object(&((*map).token.shape), (*map).token.height) : 0;
	allocate_object(&((*map).token.shape), (*map).token.height);
	i = 0;
	while (i < (*map).token.height)
	{
		get_new_line(&line);
		((*map).token.shape[i] = ft_strdup(line)) == NULL ? exit(0) : 0;
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		free(line);
		i++;
	}
}
