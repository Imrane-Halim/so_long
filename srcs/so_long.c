/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/16 17:59:06 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	check_win(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_putstr_fd("\n----->you won!\n", 1);
		close_game(data);
	}
	ft_putstr_fd("\nYou have to collect all the coins first\n", 1);
}

void	run_game(t_data data)
{
	init_window(&data);
	init_imgs(&data);
	draw_tails(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handl_input, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_game, &data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		error("usage: ./so_long <MAP.ber>");
	data.map = load_map(av[1]);
	is_valid_map(data.map);
	run_game(data);
}
