/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 15:09:01 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	init_player_frames(t_data *data)
{
	data->player.frames[0] = create_img(data,
			"assets_xpm/player_animation_xpm/player_frame_1.xpm");
	data->player.frames[1] = create_img(data,
			"assets_xpm/player_animation_xpm/player_frame_2.xpm");
	data->player.frames[2] = create_img(data,
			"assets_xpm/player_animation_xpm/player_up.xpm");
	data->player.frames[3] = create_img(data,
			"assets_xpm/player_animation_xpm/player_right_1.xpm");
	data->player.frames[4] = create_img(data,
			"assets_xpm/player_animation_xpm/player_right_2.xpm");
	data->player.frames[5] = create_img(data,
			"assets_xpm/player_animation_xpm/player_left_1.xpm");
	data->player.frames[6] = create_img(data,
			"assets_xpm/player_animation_xpm/player_left_2.xpm");
}

int	animate_player(t_data *data)
{
	data->player.timer++;
	if (data->player.timer >= 15000)
	{
		draw_player(data);
		data->player.current_frame = (data->player.current_frame + 1) % 2;
		data->player.timer = 0;
	}
	return (0);
}
