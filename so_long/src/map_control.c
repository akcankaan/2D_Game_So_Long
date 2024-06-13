/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:57:53 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/04 15:34:46 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	name_control(char *map_name, int fd)
{
	int	size;

	size = ft_strlen(map_name) - 1;
	if (ft_strncmp(ft_strrchr(map_name, '.'), ".ber",
			ft_strlen(ft_strrchr(map_name, '.'))))
		error_msg("Error\nThe map name not .ber");
	else
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
			error_msg("Error\nThe map failed to open");
		close(fd);
	}
}

void	get_map_size(t_data *data, int x, int y, int fd)
{
	char	*line;

	line = get_next_line(fd, 0, 1);
	if (!line)
		error_msg("ERROR\n--Folder not read");
	x = (int)ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd, 0, 1);
		if (!line)
			return ;
		if (line[0] == '\0')
			break ;
		if (x != (int)ft_strlen(line))
		{
			(free(line), close(fd));
			error_msg("Error\n--The map should be rectangular");
		}
	}
	free(line);
	data->map_height = y;
	data->map_width = x - 1;
}

void	map_read(t_data *data, int fd, int x, int y)
{
	char	*area;

	data->map = (char **)malloc(sizeof(char *) * data->map_height + 1);
	if (!data->map)
		(close(fd), exit(1));
	while (x < data->map_height)
	{
		area = get_next_line(fd, 0, 1);
		if (area == NULL)
			break ;
		data->map[x] = (char *)malloc(sizeof(char) * data->map_width + 2);
		if (!data->map[x])
		{
			close(fd);
			(free(area), map_free(data->map, data, 1, "\0"));
		}
		y = 0;
		while (area[y])
		{
			data->map[x][y] = area[y];
			y++;
		}
		data->map[x++][y] = '\0';
		free(area);
	}
}

void	wall_control(t_data *data, int i, int j)
{
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			map_free(data->map, data, 2,
				"ERROR\n--The Map Must Be Surrounded By Closed Walls.--");
		++i;
	}
	while (j < data->map_height)
	{
		if (data->map[j][0] != '1' || data->map[j][data->map_width - 1] != '1')
			map_free(data->map, data, 2,
				"ERROR\n->The Map Must Be Surrounded By Closed Walls.<-");
		++j;
	}
}

void	map_control(char *map_name, t_data *data)
{
	int	fd;

	data->in_map_name = map_name;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_msg("Error\n->Map file isn't found.<-");
	name_control(map_name, fd);
	close(fd);
	fd = open(data->in_map_name, O_RDONLY);
	if (fd == -1)
		error_msg("Error\n-Map file isn't found. <-");
	get_map_size(data, 0, 0, fd);
	close(fd);
	fd = open(data->in_map_name, O_RDONLY);
	if (fd == -1)
		error_msg("Error\n->Map file not found.<-");
	map_read(data, fd, 0, 0);
	close(fd);
	wall_control(data, 0, 0);
}
