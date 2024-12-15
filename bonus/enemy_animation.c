/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 15:18:06 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	init_enemy_frames(t_data *data)
{
	data->enemy.frames[0] = create_img(data,
			"assets_xpm/enemy_animation_xpm/enemy_frame_1.xpm");
	data->enemy.frames[1] = create_img(data,
			"assets_xpm/enemy_animation_xpm/enemy_frame_2.xpm");
}

void	put_all_enemys(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.colums)
		{
			if (data->map.map[y][x] == 'X')
				mlx_put_image_to_window(data->mlx, data->win,
					data->enemy.frames[data->enemy.current_frame],
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	animate_enemys(t_data *data)
{
	data->enemy.timer++;
	if (data->enemy.timer >= 15000)
	{
		put_all_enemys(data);
		data->enemy.current_frame = (data->enemy.current_frame + 1) % 2;
		data->enemy.timer = 0;
	}
	return (0);
}
