/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/14 17:43:27 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

int		get_movement_frame(int x_dir, int y_dir)
{
	static int	next;
	if (x_dir != 0)
		next = (next + 1) % 2;
	if (x_dir == 1)
		return (3 + next);
	else if (x_dir == -1)
		return (5 + next);
	else if (y_dir == -1)
		return (2);
	return (0);
}

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
	data->player.current_frame = get_movement_frame(x_dir, y_dir);
	draw_player(data);
	if (data->map.map[data->p_y - y_dir][data->p_x - x_dir] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit_closed.img,
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
		move(data, 1, 0);
	else if (key == LEFT_KEY || key == A_KEY)
		move(data, -1, 0);
	else if (key == UP_KEY || key == W_KEY)
		move(data, 0, -1);
	else if (key == DOWN_KEY || key == S_KEY)
		move(data, 0, 1);
	check_win(data);
	count = ft_itoa(data->moves_count);
	mlx_put_image_to_window(data->mlx, data->win, data->images.wall.img, 0, 0);
	mlx_string_put(data->mlx, data->win, 32, 32, 0xffffff, count);
	free(count);
	return (0);
}
