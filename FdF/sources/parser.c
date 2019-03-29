#include "../includes/fdf.h"

static void	allocate_point(t_map *map, t_point **point)
{
	int	num;
	int	x;
	int	y;

	num = map->width * map->height;
	x = map->width - 1;
	y = map->height - 1;
	if (!(*point = (t_point *)malloc(sizeof(t_point) * num)))
		error_message(6);
	while (num)
	{
		(*point)[num - 1].x = x;
		(*point)[num - 1].y = y;
		(*point)[num - 1].z = 0;
		(*point)[num - 1].color = PRIMARY_COLOR;
		x--;
		if (x < 0)
		{
			x = map->width - 1;
			y--;
		}
		num--;
	}
}

static void	allocate_map(t_map *map, t_point **point)
{
	int	num;

	map->offset_x = HORIZONTAL_RESOLUTION / 5;
	map->offset_y = VERTICAL_RESOLUTION / 5;
	map->offset_z = 1;
	map->angle_x = 45;
	map->angle_y = 0;		//	смещение y = 45, z = -30 позволит видеть фигуру
	map->angle_z = 45;		//	в стандартной прямоугольной изометрии
	map->focus = -1;
	map->zoom = 8;
	map->point = *point;
	num = map->width * map->height;
	if (!(map->backup_point = (t_point *)malloc(sizeof(t_point) * num)))
	{
		free(*point);
		exit(6);
	}
	while (num)
	{
		map->backup_point[num - 1].x = map->point[num - 1].x;
		map->backup_point[num - 1].y = map->point[num - 1].y;
		map->backup_point[num - 1].z = map->point[num - 1].z;
		map->backup_point[num - 1].color = map->point[num - 1].color;
		num--;
	}
}

static void	get_value(t_point **temp, char **line)
{
	int	value;
	int	sign;

	value = 0;
	sign = (**line == '-') ? 1 : 0;
	*line += (sign) ? 1 : 0;
	while (**line >= '0' && **line <= '9')
	{
		(*temp)->z *= 10;
		(*temp)->z += **line - '0';
		(*line)++;
	}
	(*temp)->z = (sign) ? -((*temp)->z) : (*temp)->z;
	if (**line == ',')
	{
		(*line) += 3;
		(*temp)->color = 0;
		while (**line >= '0' && **line <= 'F')
		{
			(*temp)->color *= 16;
			(*temp)->color += **line - ((**line > '9') ? ('A' - 10) : '0');
			(*line)++;
		}
	}
	(*temp)++;
}

static void	parse_line(t_point *temp, char *line)
{
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line == '-' || (*line >= '0' && *line <= '9'))
			get_value(&temp, &line);
	}
}

void		parse_map(char *filename, t_map *map, t_point **point)
{
	t_point	*temp;
	char	*line;
	int		fd;

	allocate_point(map, point);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		free(*point);
		error_message(1);
	}
	temp = *point;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
		{
			free(*point);
			error_message(2);
		}
		parse_line(temp, line);
		free(line);
		temp += map->width;
	}
	allocate_map(map, point);
	close(fd);
}
