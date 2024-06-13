/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:51:29 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/03 22:51:29 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	min_required_chars(t_data *data)
{
	if (data->player_count != 1)
	{
		map_free(data->map, data, 2,
			"ERROR\n--There must be 1 player(P) on the map--");
	}
	if (data->exit_count != 1)
	{
		map_free(data->map, data, 2,
			"ERROR\n--There must be 1 exit(E) On the map.--");
	}
	if (data->coin_count < 1)
	{
		map_free(data->map, data, 2, "ERROR\n--Must be at least 1 coin.--");
	}
}

void	chars_control(t_data *data, int i, int j)
{
	while (++i < data->map_height)
	{
		j = 0;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == '1' || data->map[i][j] == '0')
				continue ;
			else if (data->map[i][j] == 'C')
				data->coin_count++;
			else if (data->map[i][j] == 'E')
			{
				data->exit_count++;
				data->exit_x = j;
				data->exit_y = i;
			}
			else if (data->map[i][j] == 'P')
			{
				data->player_count++;
				data->player_x = j;
				data->player_y = i;
			}
			else
				map_free(data->map, data, 2, "ERROR\n-There Undefined Chars-");
		}
	}
}

void	map_chars(t_data *data)
{
	data->player_count = 0;
	data->exit_count = 0;
	data->coin_count = 0;
	data->coin_collected = 0;
	data->step_count = 0;
	chars_control(data, -1, 0);
	min_required_chars(data);
}
