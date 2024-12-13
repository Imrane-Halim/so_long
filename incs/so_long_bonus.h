/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/13 15:54:27 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

enum e_keys
{
	ESC_KEY = 65307,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

typedef struct s_imgs
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*grass;
	void	*exit;
	void	*enemy;
}	t_imgs;

typedef struct s_map
{
	char	**map;
	int		colums;
	int		rows;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_coin
{
	void	*frames[6];
	int		current_frame;
	int		timer;
}	t_coin;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgs	images;
	t_map	map;
	int		p_x;
	int		p_y;
	int		moves_count;
	int		coin_count;
	int		coin_collected;
	t_coin	coin;
}	t_data;

int animate_coins(t_data *data);
void init_frams(t_data *data);

void	free_map(t_map map);
t_map	load_map(char *filename);
void	is_valid_map(t_map map);
void	is_map_beatable(t_map map);
void	error(char *msg);

int		close_game(t_data *data);
void	init_window(t_data *data);
void	draw_tail(char taile, t_data *data, int x, int y);
void	draw_tails(t_data *data);
void	*create_img(t_data *data, char *path);
void	init_imgs(t_data *data);

void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
int		handl_input(int key, t_data *data);
void	check_win(t_data *data);

#endif