/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/14 11:15:05 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

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

unsigned int	get_color_from_img(t_img *img, int x, int y)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_player(t_data *data)
{
	static int original[64][64];
	static int init;
	t_img	img;
	t_img	*p;
	char	*dst;
	int		y;
	int		x;
	
	p = &data->images.player;
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, &p->line_length, &p->endian);

	if (!init)
	{
		init = 1;
		y = 0;
		while (y < 64)
		{
			x = 0;
			while (x < 64)
			{
				dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
				if (get_t(*(unsigned int *)dst) == 255)
					original[y][x] = 1;
				x++;
			}
			y++;
		}		
	}
	
	if (data->map.map[data->p_y][data->p_x] == 'E')
		img.img = data->images.exit.img;
	else
		img.img = data->images.grass.img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
			if (original[y][x])
				*(unsigned int *)dst = get_color_from_img(&img, x, y);
			x++;
		}
		y++;	
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player.img, data->p_x * 64, data->p_y * 64);
}

void	draw_tail(char taile, t_data *data, int x, int y)
{
	if (taile == 'C')
	{
		data->coin_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->images.coin.img, x, y);
	}
	else if (taile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images.wall.img, x, y);
	else if (taile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images.grass.img, x, y);
	else if (taile == 'P')
	{
		data->p_x = x / 64;
		data->p_y = y / 64;
		draw_player(data);
	}
	else if (taile == 'E')
	{
		data->map.exit_x = x / 64;
		data->map.exit_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit.img, x, y);
	}
	else if (taile == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->images.enemy.img, x, y);
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
	
	data->images.coin.img = create_img(data, "textures_xpm/coin.xpm");
	data->images.wall.img = create_img(data, "textures_xpm/wall.xpm");
	data->images.player.img = create_img(data, "textures_xpm/player_transparent.xpm");
	data->images.grass.img = create_img(data, "textures_xpm/grass.xpm");
	data->images.exit.img = create_img(data, "textures_xpm/exit.xpm");
	//data->images.player_exit.img = create_img(data, "textures_xpm/player_on_exit.xpm");
	data->images.enemy.img = create_img(data, "textures_xpm/enemy.xpm");
}
