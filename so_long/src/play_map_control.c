/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_map_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:48:10 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/03 17:12:24 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

static void	visit_map(int **int_map, t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P' || data->map[y][x] == 'C')
	{
		data->i_map.read_count++;
	}
	if (data->map[y][x + 1] != '1' && int_map[y][x + 1] < 1)
	{
		int_map[y][x + 1] = int_map[y][x] + 1;
		visit_map(int_map, data, x + 1, y);
	}
	if (data->map[y + 1][x] != '1' && int_map[y + 1][x] < 1)
	{
		int_map[y + 1][x] = int_map[y][x] + 1;
		visit_map(int_map, data, x, y + 1);
	}
	if (data->map[y][x - 1] != '1' && int_map[y][x - 1] < 1)
	{
		int_map[y][x - 1] = int_map[y][x] + 1;
		visit_map(int_map, data, x - 1, y);
	}
	if (data->map[y - 1][x] != '1' && int_map[y - 1][x] < 1)
	{
		int_map[y - 1][x] = int_map[y][x] + 1;
		visit_map(int_map, data, x, y - 1);
	}
}

static void	print(t_data *data)
{
	if (data->i_map.read_count == data->coin_count + 1)
		ft_printf("\n--MAP OK--\n");
	ft_printf("\nCollected Available: %d\n", data->i_map.read_count);
}

static void	int_map_free(int **int_map, t_data *data, int flag)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
	if (flag == 1)
		map_free(data->map, data, 2,
			"ERROR\nMemory Allocation Error!");
}

void	playable_map(t_data *data, int x, int y, int i)
{
	int	**int_map;
	int	j;

	int_map = (int **)malloc(sizeof(int *) * data->map_height);
	if (!int_map)
		int_map_free(int_map, data, 1);
	while (i < data->map_height)
	{
		int_map[i] = (int *)malloc(sizeof(int) * data->map_width);
		if (!int_map[i])
			int_map_free(int_map, data, 1);
		j = -1;
		while (++j < data->map_width)
		{
			int_map[i][j] = 0;
		}
		i++;
	}
	int_map[y][x] = 1;
	data->i_map.read_count = 0;
	visit_map(int_map, data, x, y);
	print(data);
	int_map_free(int_map, data, 0);
}
