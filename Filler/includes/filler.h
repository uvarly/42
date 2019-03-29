/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:18:49 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/12 13:18:50 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_token
{
	int		width;
	int		height;

	int		x;
	int		y;

	char	**shape;
}				t_token;

typedef struct	s_map
{
	int		width;
	int		height;

	int		initial_turn;
	int		contact;

	int		my_letter[2];
	int		op_letter[2];


	char	**field;
	t_token	token;
}				t_map;

void			determine_move_order(t_map *map, int fd);
void			determine_map_size(t_map *map, int fd);
void			determine_field(t_map *map, int fd);
void			determine_token_size(t_map *map, int fd);
void			determine_token(t_map *map, int fd);

void			initialize_structure(t_map *map);
void			get_new_line(char **line);
void			allocate_object(char ***object, int height);
void			destroy_object(char ***object, int height);
int				is_my_piece(t_map *map, char piece);

void			place_token(t_map *map, int fd);

#endif
