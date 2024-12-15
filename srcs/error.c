/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 13:26:32 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.coin);
	mlx_destroy_image(data->mlx, data->images.exit);
	mlx_destroy_image(data->mlx, data->images.grass);
	mlx_destroy_image(data->mlx, data->images.player);
	mlx_destroy_image(data->mlx, data->images.wall);
}

int	close_game(t_data *data)
{
	free_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}
