/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobilize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:44:51 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/03 12:44:52 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

static int	after_move( t_data *data, int y, int x)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return (0);
	else if (data->map[data->player_y + y][data->player_x + x] == 'C')
	{
		ft_printf("\n--Stone Collected--\n");
		data->map[data->player_y + y][data->player_x + x] = '0';
		data->coin_collected++;
	}
	else if (data->map[data->player_y + y][data->player_x + x] == 'E')
	{
		if (data->coin_collected == data->coin_count)
		{
			ft_printf("	--Exit Made--");
			exit_door(data);
		}
		else
			ft_printf("\n%s\n", "--There Are Uncollected Stones On The Map.--");
	}
	return (1);
}

static int	move(t_data *data, int keycode, int x)
{
	if (keycode == 0 || keycode == 2)
	{
		if (after_move(data, 0, x) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.background,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		data->player_x += x;
	}
	if (keycode == 13 || keycode == 1)
	{
		if (after_move(data, -x, 0) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.background,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
		data->player_y -= x;
	}
	data->step_count++;
	ft_printf("STEP: %d\r", data->step_count);
	after_image(data);
	return (0);
}

void	after_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.background,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.character,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	if (data->map[data->exit_y][data->exit_x])
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.door,
			data->exit_x * IMG_SIZE, data->exit_y * IMG_SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img.character,
			data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		destroy(data);
		map_free(data->map, data, 2, "--Exit Success--");
	}
	else if (keycode == 2 || keycode == 13)
		move(data, keycode, 1);
	else if (keycode == 0 || keycode == 1)
		move(data, keycode, -1);
	return (0);
}
