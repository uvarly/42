/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 09:33:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/02/24 12:19:58 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define HORIZONTAL_RESOLUTION 1366
# define VERTICAL_RESOLUTION 768
# define PRIMARY_COLOR 0xf4bf42

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct	s_map
{
	int		width;			//	кол-во точек по X
	int		height;			//	кол-во точек по Y
	float	offset_x;
	float	offset_y;
	float	offset_z;
	int		angle_x;		//	смещение точки по оси X (в град)
	int		angle_y;		//	смещение точки по оси Y (в град)
	int		angle_z;		//	смещение точки по оси Z (в град)
	int		focus;			//	фокальное расстояние
	int		zoom;			//	масштаб
	t_point	*point;			//	карта точек, которую мы изменяем для создания поворотов и вывода линий на экран
	t_point *backup_point;	//	резервная изначальная карта, к которой мы будем возвращаться при необходимости
}				t_map;

typedef struct	s_image
{
	void	*img_ptr;
	int		*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_line
{
	int	dx;
	int	dy;
	int	sign_x;
	int	sign_y;
	int	error;
	int	temp;
}				t_line;


typedef struct	s_mlx			//	"внешняя" структура, которая хранит в себе mlx-указатели, карту точек и картинку
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_image image;
}				t_mlx;

void		error_message(int err_num);

void		is_map_valid(char **argv, t_map *map);
void		parse_map(char *filename, t_map *map, t_point **point);
void		rotate_map(t_mlx *mlx, t_map map);
void		print_map(t_mlx mlx);
void		print_lines(t_mlx mlx, t_map map, t_image image);
void		print_borders(t_mlx mlx);

#endif