/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 10:36:05 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

static void	dfs(t_map map, int y, int x, char **visited)
{
	if (x < 0 || x >= map.colums || y < 0 || y >= map.rows
		|| map.map[y][x] == '1' || visited[y][x] == 'f' || visited[y][x] == 'X')
		return ;
	visited[y][x] = 'f';
	dfs(map, y + 1, x, visited);
	dfs(map, y - 1, x, visited);
	dfs(map, y, x + 1, visited);
	dfs(map, y, x - 1, visited);
}

static char **tmp_map(t_map map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (map.rows + 1));
	while (i < map.rows)
	{
		tmp[i] = malloc(sizeof(char) * (map.colums + 1));
		ft_strcpy(tmp[i], map.map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void free_tmp(char **tmp)
{
	int i;
	
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static int	check_char(char **tmp, char c)
{
	int	y;
	int	x;

	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	is_map_beatable(t_map map)
{
	char	**visited;
	int		x;
	int		y;

	y = 0;
	while (y < map.rows)
	{
		x = -1;
		while (++x < map.colums)
		{
			if (map.map[y][x] == 'P')
				break ;
		}
		if (map.map[y][x] == 'P')
			break ;
		y++;
	}
	visited = tmp_map(map);
	dfs(map, y, x, visited);
	if (check_char(visited, 'E') || check_char(visited, 'C'))
	{
		free_map(map);
		error("Error: Invalid map, exit unreachable or coins uncollectible.\n");
	}
	free_tmp(visited);
}
