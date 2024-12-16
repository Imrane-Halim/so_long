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

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data->map);
		error("couldn't connect to x server.");
	}
	data->win = mlx_new_window(data->mlx,
			data->map.colums * 64,
			data->map.rows * 64, "so_long");
	if (!data->win)
	{
		free_map(data->map);
		free(data->mlx);
		error("couldn't create a new window.");
	}
}

static t_img	select_background_image(t_data *data)
{
	t_img	img;

	if (data->map.map[data->p_y][data->p_x] == 'E')
		img.img = data->images.exit_closed.img;
	else
		img.img = data->images.grass.img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

static void	blend_player_with_background(t_img *comp,
	t_img *background, t_img *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			if (get_t(get_color_from_img(player, x, y)) == 255)
				my_mlx_pixel_put(comp, x, y,
					get_color_from_img(background, x, y));
			else
				my_mlx_pixel_put(comp, x, y,
					get_color_from_img(player, x, y));
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	t_img	*comp;
	t_img	background;
	t_img	player;

	comp = &data->images.comp;
	player.img = data->player.frames[data->player.current_frame];
	player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel,
			&player.line_length, &player.endian);
	background = select_background_image(data);
	blend_player_with_background(comp, &background, &player);
	mlx_put_image_to_window(data->mlx, data->win, comp->img,
		data->p_x * 64, data->p_y * 64);
}

void	init_imgs(t_data *data)
{
	t_img	*img;

	data->images.coin.img = create_img(data,
			"textures/textures_xpm/coin.xpm");
	data->images.wall.img = create_img(data,
			"textures/textures_xpm/wall.xpm");
	data->images.grass.img = create_img(data,
			"textures/textures_xpm/grass.xpm");
	data->images.exit_closed.img = create_img(data,
			"textures/textures_xpm/exit_closed.xpm");
	data->images.exit_open.img = create_img(data,
			"textures/textures_xpm/exit_open.xpm");
	data->images.enemy.img = create_img(data,
			"textures/textures_xpm/enemy.xpm");
	data->images.comp.img = mlx_new_image(data->mlx, 64, 64);
	img = &data->images.comp;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
