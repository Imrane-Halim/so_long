#include "../incs/so_long_bonus.h"

void init_player_frames(t_data *data)
{
	data->player.frames[0] = create_img(data, "player_animation_xpm/player_frame_1.xpm");
	data->player.frames[1] = create_img(data, "player_animation_xpm/player_frame_2.xpm");
}
int    animate_player(t_data *data)
{
    data->player.timer++;
    if (data->player.timer >= 15000)
    {
        draw_player(data);
        data->player.current_frame = (data->player.current_frame + 1) % 2;
        data->player.timer = 0;
    }
    return 0;
}