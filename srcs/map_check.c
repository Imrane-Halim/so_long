/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 14:24:43 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	check_chars(t_map map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			c = map.map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
			{
				free_map(map);
				error("Error: Invalid map, invalid char exists\n");
			}
			x++;
		}
		y++;
	}
}

static void	check_rectangle(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.colums != (int)ft_strlen(map.map[i]))
		{
			free_map(map);
			error("Error: Inalid map, not a perfect rectangle\n");
		}
		i++;
	}
}

static void	check_walls(t_map map)
{
	int	i;

	i = 0;
	while (i < map.colums)
	{
		if (map.map[0][i] != '1' || map.map[map.rows - 1][i] != '1')
		{
			free_map(map);
			error("Error: Ivalid map, check your walls\n");
		}
		i++;
	}
	i = 1;
	while (i < map.rows - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.colums - 1] != '1')
		{
			free_map(map);
			error("Error: Ivalid map, check your walls\n");
		}
		i++;
	}
}

static void	check_flags(t_map map)
{
	static int	coin;
	int			player;
	int			exit;
	int			x;

	exit = 0;
	player = 0;
	while (--map.rows)
	{
		x = 0;
		while (*(map.map[map.rows] + x++))
		{
			if (*(map.map[map.rows] + x - 1) == 'C')
				coin = 1;
			else if (*(map.map[map.rows] + x - 1) == 'P')
				player++;
			else if (*(map.map[map.rows] + x - 1) == 'E')
				exit++;
		}
	}
	if ((coin * player * exit) != 1)
	{
		free_map(map);
		error("Error: Invalid map. P=1Max, C=1Min, E=1Max\n");
	}
}

void	is_valid_map(t_map map)
{
	check_chars(map);
	check_rectangle(map);
	check_walls(map);
	check_flags(map);
	is_map_beatable(map);
	if (map.rows > 32 || map.colums > 60)
	{
		free_map(map);
		error("Error: Invalid map, too big for screen\n");
	}
}
