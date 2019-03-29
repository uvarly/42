#include "../includes/fdf.h"

static void		apply_zoom(t_map *map, int i)
{
	(*map).point[i].x *= (*map).zoom;
	(*map).point[i].y *= (*map).zoom;
	(*map).point[i].z *= (*map).zoom;
}

static void		rotate_x(t_map *map, int i)
{
	float	x;
	float	y;
	float	z;
	float	rad;

	x = (*map).backup_point[i].x;
	y = (*map).backup_point[i].y;
	z = (*map).backup_point[i].z * (*map).offset_z;
	rad = M_PI / 180;
	(*map).point[i].x = (
		x * cosf((*map).angle_y * rad) * cosf((*map).angle_z * rad) -
		y * cosf((*map).angle_y * rad) * sinf((*map).angle_z * rad) +
		z * sinf((*map).angle_y * rad)) * (*map).zoom + (*map).offset_x;
}

static void		rotate_y(t_map *map, int i)
{
	float	x;
	float	y;
	float	z;
	float	rad;

	x = (*map).backup_point[i].x;
	y = (*map).backup_point[i].y;
	z = (*map).backup_point[i].z * (*map).offset_z;
	rad = M_PI / 180;
	(*map).point[i].y = (
		x * (sinf((*map).angle_x * rad)
				* sinf((*map).angle_y * rad)
				* cosf((*map).angle_z * rad)
		+ cosf((*map).angle_x * rad) * sinf((*map).angle_z * rad)) +
		y * (cosf((*map).angle_x * rad)
				* cosf((*map).angle_z * rad)
		- sinf((*map).angle_x * rad)
				* sinf((*map).angle_y * rad)
				* sinf((*map).angle_z * rad)) -
		z * cosf((*map).angle_y * rad)
				* sinf((*map).angle_x * rad))
				* (*map).zoom + (*map).offset_y;
}

static void		rotate_z(t_map *map, int i)
{
	float	x;
	float	y;
	float	z;
	float	rad;

	x = (*map).backup_point[i].x;
	y = (*map).backup_point[i].y;
	z = (*map).backup_point[i].z * (*map).offset_z;
	rad = M_PI / 180;
	(*map).point[i].z = (
		x * (sinf((*map).angle_x * rad)
				* sinf((*map).angle_z * rad)
		- cosf((*map).angle_x * rad)
				* sinf((*map).angle_y * rad)
				* cosf((*map).angle_z * rad)) +
		y * (cosf((*map).angle_x * rad)
				* sinf((*map).angle_y * rad)
				* sinf((*map).angle_z * rad)
		+ sinf((*map).angle_x * rad)
				* cos((*map).angle_z * rad)) +
		z * cosf((*map).angle_x * rad)
				* cosf((*map).angle_y * rad))
				* (*map).zoom + (*map).offset_z;
}

void			rotate_map(t_mlx *mlx, t_map map)
{
	int		num;

	(*mlx).map = map;
	num = (*mlx).map.width * (*mlx).map.height;
	while (num)
	{
		rotate_x(&((*mlx).map), num - 1);
		rotate_y(&((*mlx).map), num - 1);
		rotate_z(&((*mlx).map), num - 1);
		(*mlx).map.point[num - 1].x = roundf((*mlx).map.point[num - 1].x);
		(*mlx).map.point[num - 1].y = roundf((*mlx).map.point[num - 1].y);
		(*mlx).map.point[num - 1].z = roundf((*mlx).map.point[num - 1].z);
		num--;
	}
}
