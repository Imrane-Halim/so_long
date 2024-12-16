/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/16 17:16:05 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	check_win(t_data *data)
{
	if (data->p_x == data->map.exit_x && data->p_y == data->map.exit_y)
	{
		if (data->coin_collected == data->coin_count)
		{
			ft_putstr_fd("\n----->you won!\n", 1);
			close_game(data);
		}
		mlx_string_put(data->mlx, data->win, 70, 32, 0xffffffff,
			"You have to collect all the coins first");
	}
	if (data->map.map[data->p_y][data->p_x] == 'X')
	{
		ft_putstr_fd("\n----->Lost! You touched an enemy patrol!\n", 1);
		close_game(data);
	}
}

void	update_door(t_data *data)
{
	if (data->coin_collected == data->coin_count)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.exit_open.img,
			data->map.exit_x * 64, data->map.exit_y * 64);
}

int	animate(t_data *data)
{
	if (data->coin_collected != data->coin_count)
		animate_coins(data);
	animate_player(data);
	update_door(data);
	animate_enemys(data);
	return (0);
}

void	run_game(t_data data)
{
	init_window(&data);
	init_imgs(&data);
	data.coin.current_frame = 0;
	data.coin.timer = 0;
	data.player.current_frame = 0;
	data.player.timer = 0;
	data.enemy.current_frame = 0;
	data.enemy.timer = 0;
	init_coin_frames(&data);
	init_player_frames(&data);
	init_enemy_frames(&data);
	draw_tails(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handl_input, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_game, &data);
	mlx_loop_hook(data.mlx, animate, &data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		error("usage: ./so_long <MAP.ber>\n");
	data.map = load_map(av[1]);
	is_valid_map(data.map);
	run_game(data);
}
