/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:03:57 by uvarly            #+#    #+#             */
/*   Updated: 2019/01/06 12:03:59 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

short	g_scale;

void	adjust_scale(char **input);
char	*increase_scale(char *object);
char	*decrease_scale(char *object);
int		is_figure_valid(char *figure);
int		standartize_input(char ***input);
int		offset_figure(char *figure);
int		is_able_to_offset_furhter(char *figure);
void	reset_figure(char *figure);
int		get_input(char ***input, char *file_name);
int		fill_map(char *map, char **figure, char letter);
void	print_figure(char *figure);
int		print_error_message(void);
int		print_error_message_invalid(void);
void	erase_all_memory(char ***input, char **map);

#endif
