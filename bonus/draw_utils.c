/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   game_render_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 10:45:40 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_other_tail(char taile, t_data *data, int x, int y)
{
	if (taile == 'C')
	{
		data->coin_count++;
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.coin.img, x, y);
	}
	else if (taile == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.wall.img, x, y);
	else if (taile == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.grass.img, x, y);
	else if (taile == 'X')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.enemy.img, x, y);
}

void	draw_tail(char taile, t_data *data, int x, int y)
{
	if (taile == 'P')
	{
		data->p_x = x / 64;
		data->p_y = y / 64;
		draw_player(data);
	}
	else if (taile == 'E')
	{
		data->map.exit_x = x / 64;
		data->map.exit_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.exit_closed.img, x, y);
	}
	else
		draw_other_tail(taile, data, x, y);
}

void	draw_tails(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->coin_count = 0;
	data->coin_collected = 0;
	data->moves_count = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			draw_tail(data->map.map[y][x], data, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	*create_img(t_data *data, char *path)
{
	int	x;
	int	y;

	return (mlx_xpm_file_to_image(data->mlx, path, &x, &y));
}
