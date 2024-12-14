/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/14 12:26:48 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

#define DOWN 0, 1
#define UP 0, -1
#define RIGHT 1, 0
#define LEFT -1, 0

void	move(t_data *data, int x_dir, int y_dir)
{
	if (data->map.map[data->p_y + y_dir][data->p_x + x_dir] == '1')
		return ;
	data->p_x += x_dir;
	data->p_y += y_dir;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	draw_player(data);
	if (data->map.map[data->p_y - y_dir][data->p_x - x_dir] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit.img,
		(data->p_x - x_dir) * 64, (data->p_y - y_dir) * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->images.grass.img,
			(data->p_x - x_dir) * 64, (data->p_y - y_dir) * 64);
}

int	handl_input(int key, t_data *data)
{
	char	*count;

	if (key == ESC_KEY)
		close_game(data);
	else if (key == RIGHT_KEY || key == D_KEY)
		move(data, RIGHT);
	else if (key == LEFT_KEY || key == A_KEY)
		move(data, LEFT);
	else if (key == UP_KEY || key == W_KEY)
		move(data, UP);
	else if (key == DOWN_KEY || key == S_KEY)
		move(data, DOWN);
	check_win(data);
	count = ft_itoa(data->moves_count);
	mlx_put_image_to_window(data->mlx, data->win, data->images.wall.img, 0, 0);
	mlx_string_put(data->mlx, data->win, 32, 32, 0xffffff, count);
	free(count);
	return (0);
}
