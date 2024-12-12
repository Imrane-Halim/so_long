/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/12 10:45:51 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	move_right(t_data *data)
{
	if (data->map.map[data->p_y][data->p_x + 1] == '1')
		return ;
	data->p_x++;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player,
		data->p_x * 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass,
		(data->p_x - 1) * 64, data->p_y * 64);
}

void	move_left(t_data *data)
{
	if (data->map.map[data->p_y][data->p_x - 1] == '1')
		return ;
	data->p_x--;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player,
		data->p_x * 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass,
		(data->p_x + 1) * 64, data->p_y * 64);
}

void	move_up(t_data *data)
{
	if (data->map.map[data->p_y - 1][data->p_x] == '1')
		return ;
	data->p_y--;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player,
		data->p_x * 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass,
		data->p_x * 64, (data->p_y + 1) * 64);
}

void	move_down(t_data *data)
{
	if (data->map.map[data->p_y + 1][data->p_x] == '1')
		return ;
	data->p_y++;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player,
		data->p_x * 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass,
		data->p_x * 64, (data->p_y - 1) * 64);
}

int	handl_input(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_game(data);
	else if (key == RIGHT_KEY || key == D_KEY)
		move_right(data);
	else if (key == LEFT_KEY || key == A_KEY)
		move_left(data);
	else if (key == UP_KEY || key == W_KEY)
		move_up(data);
	else if (key == DOWN_KEY || key == S_KEY)
		move_down(data);
	if (data->p_x == data->map.exit_x && data->p_y == data->map.exit_y)
		check_win(data);
	if (data->p_x != data->map.exit_x || data->p_y != data->map.exit_y)
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit,
			data->map.exit_x * 64, data->map.exit_y * 64);
	ft_putstr_fd("\ncout: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
	return (0);
}
