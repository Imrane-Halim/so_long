#include "../incs/so_long_bonus.h"

void init_coin_frames(t_data *data)
{
	data->coin.frames[0] = create_img(data, "coin_animation_xpm/coin1.xpm");
	data->coin.frames[1] = create_img(data, "coin_animation_xpm/coin2.xpm");
	data->coin.frames[2] = create_img(data, "coin_animation_xpm/coin3.xpm");
	data->coin.frames[3] = create_img(data, "coin_animation_xpm/coin4.xpm");
	data->coin.frames[4] = create_img(data, "coin_animation_xpm/coin5.xpm");
	data->coin.frames[5] = create_img(data, "coin_animation_xpm/coin6.xpm");
}

void put_all_coins(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.colums)
		{
			if (data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->coin.frames[data->coin.current_frame], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int animate_coins(t_data *data)
{
	data->coin.timer++;
	if (data->coin.timer >= 5500)
	{
		put_all_coins(data);
		data->coin.current_frame = (data->coin.current_frame + 1) % 6;
		data->coin.timer = 0;
	}
	return 0;
}
