/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:01:25 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/24 12:19:58 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		error_message(int err_num)
{
	(err_num == 0) ? write(1, "Illegal number of arguments\n", 28) : 0;
	(err_num == 1) ? write(1, "Invalid file name\n", 18) : 0;
	(err_num == 2) ? write(1, "Invalid map\n", 12) : 0;
	(err_num == 3) ? write(1, "Invalid map. Illegal symbol(s)\n", 31) : 0;
	(err_num == 4) ? write(1, "Invalid map. Column amount mismatch\n", 36) : 0;
	(err_num == 5) ? write(1, "Internal reading error\n", 23) : 0;
	(err_num == 6) ? write(1, "Internal memory allocation error\n", 33) : 0;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_point	*point;

	(argc != 2) ? error_message(0) : is_map_valid(argv, &map);
	parse_map(argv[1], &map, &point);
	rotate_map(&mlx, map);
	print_map(mlx);
	return (0);
}
