#include "../includes/fdf.h"

int			key_hook(int key, t_mlx *mlx)
{
	(key == 53) ? exit(0) : 0;
	(*mlx).map.offset_x += (key == 123) ? 15 : 0;
	(*mlx).map.offset_x -= (key == 124 && (*mlx).map.offset_x > 10) ? 10 : 0;
	(*mlx).map.offset_y += (key == 126) ? 15 : 0;
	(*mlx).map.offset_y -= (key == 125) ? 15 : 0;
	(*mlx).map.offset_z += (key == 116) ? 0.1 : 0;
	(*mlx).map.offset_z -= (key == 121) ? 0.1 : 0;
	(*mlx).map.angle_x += (key == 13) ? 5 : 0;
	(*mlx).map.angle_x -= (key == 1) ? 5 : 0;
	(*mlx).map.angle_y += (key == 14) ? 5 : 0;
	(*mlx).map.angle_y -= (key == 12) ? 5 : 0;
	(*mlx).map.angle_z += (key == 2) ? 5 : 0;
	(*mlx).map.angle_z -= (key == 0) ? 5 : 0;
	(*mlx).map.zoom *= (key == 69 || key == 24) && (*mlx).map.zoom < 1024 ? 2 : 1;
	(*mlx).map.zoom /= (key == 78 || key == 27) && (*mlx).map.zoom > 1 ? 2 : 1;
	if (key == 36)
	{
		(*mlx).map.offset_x = HORIZONTAL_RESOLUTION / 5;
		(*mlx).map.offset_y = VERTICAL_RESOLUTION / 5;
		(*mlx).map.offset_z = 1;
		(*mlx).map.angle_x = 45;
		(*mlx).map.angle_y = 0;
		(*mlx).map.angle_z = 45;
		(*mlx).map.zoom = 8;
	}
	rotate_map(mlx, (*mlx).map);
	mlx_clear_window((*mlx).mlx_ptr, (*mlx).win_ptr);
	print_lines(*mlx, (*mlx).map, (*mlx).image);
	print_borders(*mlx);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
	{
		(*mlx).map.offset_x = x;
		(*mlx).map.offset_y = y;
	}
	(*mlx).map.zoom *= (button == 4 && (*mlx).map.zoom < 1024) ? 2 : 1;
	(*mlx).map.zoom /= (button == 5 && (*mlx).map.zoom > 1) ? 2 : 1;
	rotate_map(mlx, (*mlx).map);
	mlx_clear_window((*mlx).mlx_ptr, (*mlx).win_ptr);
	print_lines(*mlx, (*mlx).map, (*mlx).image);
	print_borders(*mlx);
	return (0);
}

static void	color_border(int *img_data)
{
	int	i;

	i = 0;
	while (i <= HORIZONTAL_RESOLUTION)
	{
		img_data[i - 1] = 0xFFFFFF;
		i++;
	}
	while (i <= HORIZONTAL_RESOLUTION * (VERTICAL_RESOLUTION / 10) - HORIZONTAL_RESOLUTION)
	{
		img_data[i - 1] = PRIMARY_COLOR;
		i++;
	}
	while (i <= HORIZONTAL_RESOLUTION * (VERTICAL_RESOLUTION / 10))
	{
		img_data[i - 1] = 0xFFFFFF;
		i++;
	}
}

void		print_borders(t_mlx mlx)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx.mlx_ptr, HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION / 10);
	image.img_data = (int *)mlx_get_data_addr(image.img_ptr, &(image.bits_per_pixel), &(image.size_line), &(image.endian));
	color_border(image.img_data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image.img_ptr, 0, -1);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image.img_ptr, 0, VERTICAL_RESOLUTION - (VERTICAL_RESOLUTION / 15) - 1);
	mlx_destroy_image(mlx.mlx_ptr, image.img_ptr);
}

static void	print_brezenham_line(int *img_data, int x0, int y0, int x1, int y1)
{
	t_line	line;

	line.dx = (x1 > x0) ? x1 - x0 : x0 - x1;
	line.dy = (y1 > y0) ? y1 - y0 : y0 - y1;
	line.sign_x = (x1 >= x0) ? 1 : -1;
	line.sign_y = (y1 >= y0) ? 1 : -1;
	line.error = line.dx - line.dy;
	if (x1 > 0 && x1 < HORIZONTAL_RESOLUTION - 1 && y1 > 0 && y1 < VERTICAL_RESOLUTION - 1 && x1 + y1 * HORIZONTAL_RESOLUTION < HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION)
		img_data[x1 + y1 * HORIZONTAL_RESOLUTION] = PRIMARY_COLOR;
	while (x0 != x1 || y0 != y1)
	{
		if (x0 > 0 && x0 < HORIZONTAL_RESOLUTION - 1 && y0 > 0 && y0 < VERTICAL_RESOLUTION - 1 && x0 + y0 * HORIZONTAL_RESOLUTION < HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION)
			img_data[x0 + y0 * HORIZONTAL_RESOLUTION] = PRIMARY_COLOR;
		line.temp = 2 * line.error;
		if (line.temp > -line.dy)
		{
			line.error -= line.dy;
			x0 += line.sign_x;
		}
		if (line.temp < line.dx)
		{
			line.error += line.dx;
			y0 += line.sign_y;
		}
	}
}

void		print_lines(t_mlx mlx, t_map map, t_image image)
{
	int		i;
	int		j;

	image.img_ptr = mlx_new_image(mlx.mlx_ptr, HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION);
	image.img_data = (int *)mlx_get_data_addr(image.img_ptr, &(image.bits_per_pixel), &(image.size_line), &(image.endian));
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (j % map.width != map.width - 1)
				print_brezenham_line(image.img_data,	map.point[i * map.width + j].x, map.point[i * map.width + j].y,
														map.point[i * map.width + j + 1].x, map.point[i * map.width + j + 1].y);
			if (i % map.height != map.height - 1)
				print_brezenham_line(image.img_data,	map.point[i * map.width + j].x, map.point[i * map.width + j].y,
														map.point[(i + 1) * map.width + j].x, map.point[(i + 1) * map.width + j].y);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image.img_ptr, 0, 0);
	mlx_destroy_image(mlx.mlx_ptr, image.img_ptr);
}

void		print_map(t_mlx mlx)
{
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION, "new_window");

	print_lines(mlx, mlx.map, mlx.image);
	print_borders(mlx);

	mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
