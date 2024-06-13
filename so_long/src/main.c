/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:27:22 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/04 15:27:22 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		error_msg("Error\n--Only 2 Arguments Needed.--");
	map_control(av[1], &data);
	map_chars(&data);
	mlx_create(&data);
	map_free(data.map, &data, 0, "\0");
}
