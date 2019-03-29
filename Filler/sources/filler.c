/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:16:46 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/12 13:16:48 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(void)
{
	t_map	map;
	int		fd;

	initialize_structure(&map);
	if ((fd = open("debug_info.txt", O_WRONLY | O_APPEND | O_CREAT)) < 0)
		return (0);
	determine_move_order(&map, fd);
	// while (1)
	// {
		determine_map_size(&map, fd);
		determine_field(&map, fd);
		determine_token_size(&map, fd);
		determine_token(&map, fd);
		place_token(&map, fd);
	// }
	close(fd);
	return (0);
}
