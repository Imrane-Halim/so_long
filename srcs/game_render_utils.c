/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/14 17:52:50 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data->map);
		error("Error: couldn't connect to x server\n");
	}
	data->win = mlx_new_window(data->mlx,
			data->map.colums * 64,
			data->map.rows * 64, "so_long");
	if (!data->win)
	{
		free_map(data->map);
		free(data->mlx);
		error("Error: couldn't create a new window\n");
	}
}

void	draw_tail(char taile, t_data *data, int x, int y)
{
	if (taile == 'C')
	{
		data->coin_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->images.coin, x, y);
	}
	else if (taile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images.wall, x, y);
	else if (taile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images.grass, x, y);
	else if (taile == 'P')
	{
		data->p_x = x / 64;
		data->p_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->win,
			data->images.player, x, y);
	}
	else if (taile == 'E')
	{
		data->map.exit_x = x / 64;
		data->map.exit_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit, x, y);
	}
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

void	init_imgs(t_data *data)
{
	data->images.coin = create_img(data, "textures_xpm/coin.xpm");
	data->images.wall = create_img(data, "textures_xpm/wall.xpm");
	data->images.player = create_img(data, "player_animation_xpm/player_frame_1.xpm");
	data->images.grass = create_img(data, "textures_xpm/grass.xpm");
	data->images.exit = create_img(data, "textures_xpm/exit_closed.xpm");
}
