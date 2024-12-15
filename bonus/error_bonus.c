/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 12:04:50 by ihalim           ###   ########.fr       */
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
	// mlx_destroy_image(data->mlx, data->images.coin.img);
	// mlx_destroy_image(data->mlx, data->images.player.img);
	// mlx_destroy_image(data->mlx, data->images.comp.img);
	// mlx_destroy_image(data->mlx, data->images.enemy.img);
	// mlx_destroy_image(data->mlx, data->images.exit_closed.img);
	// mlx_destroy_image(data->mlx, data->images.exit_open.img);
	// mlx_destroy_image(data->mlx, data->images.grass.img);
	// mlx_destroy_image(data->mlx, data->images.wall.img);

	mlx_destroy_image(data->mlx, data->coin.frames[0]);
	mlx_destroy_image(data->mlx, data->coin.frames[1]);
	mlx_destroy_image(data->mlx, data->coin.frames[2]);
	mlx_destroy_image(data->mlx, data->coin.frames[3]);
	mlx_destroy_image(data->mlx, data->coin.frames[4]);
	mlx_destroy_image(data->mlx, data->coin.frames[5]);
	
	mlx_destroy_image(data->mlx, data->player.frames[0]);
	mlx_destroy_image(data->mlx, data->player.frames[1]);
	mlx_destroy_image(data->mlx, data->player.frames[2]);
	mlx_destroy_image(data->mlx, data->player.frames[3]);
	mlx_destroy_image(data->mlx, data->player.frames[4]);
	mlx_destroy_image(data->mlx, data->player.frames[5]);
	mlx_destroy_image(data->mlx, data->player.frames[6]);
}

int	close_game(t_data *data)
{
	free_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(0);
	return (0);
}
