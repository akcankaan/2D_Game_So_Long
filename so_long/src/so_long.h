/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehakcan <mehakcan@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:51:57 by mehakcan          #+#    #+#             */
/*   Updated: 2024/06/03 22:51:57 by mehakcan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 96

typedef struct l_image
{
	void	*character;
	void	*wall;
	void	*coin;
	void	*door;
	void	*background;
	int		img_w;
	int		img_h;
}	t_image;

typedef struct l_int_map
{
	int	read_count;
}	t_int_map;

typedef struct l_data
{
	char		**map;
	char		*mlx;
	char		*win;
	char		*in_map_name;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			player_count;
	int			exit_x;
	int			exit_y;
	int			exit_count;
	int			coin_count;
	int			coin_collected;
	int			step_count;
	int			err_x;
	t_image		img;
	t_int_map	i_map;
}	t_data;

void	mlx_create(t_data *data);
void	map_control(char *map_name, t_data *data);
void	name_control(char *map_name, int fd);
void	map_read(t_data *data, int fd, int x, int y);
void	get_map_size(t_data *data, int x, int y, int fd);
char	*get_next_line(int fd, int i, int rd_byte);
void	error_msg(char *msg);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(t_data *data);
void	exit_door(t_data *data);
void	map_background_put(t_data *data);
void	playable_map(t_data *data, int x, int y, int i);
void	wall_control(t_data *data, int i, int j);
void	after_image(t_data *data);
void	map_chars(t_data *data);
void	map_free(char **map, t_data *data, int flag, char *msg);
void	destroy(t_data *data);

#endif
