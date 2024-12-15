/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 11:41:36 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_imgs(t_data *data)
{
	free(data->images.coin.img);
	free(data->images.player.img);
	free(data->images.comp.img);
	free(data->images.enemy.img);
	free(data->images.exit_closed.img);
	free(data->images.exit_open.img);
	free(data->images.grass.img);
	free(data->images.wall.img);

	free(data->coin.frames[0]);
	free(data->coin.frames[1]);
	free(data->coin.frames[2]);
	free(data->coin.frames[3]);
	free(data->coin.frames[4]);
	free(data->coin.frames[5]);
	
	free(data->player.frames[0]);
	free(data->player.frames[1]);
	free(data->player.frames[2]);
	free(data->player.frames[3]);
	free(data->player.frames[4]);
	free(data->player.frames[5]);
	free(data->player.frames[6]);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	free_imgs(data);
	exit(0);
	return (0);
}
