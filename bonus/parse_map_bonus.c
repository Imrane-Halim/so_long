/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 11:54:48 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

static int	open_file(char *filename)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(filename, '.');
	if (ext == NULL)
		error("Error: the map should have .ber extention\n");
	if (ft_strncmp(ext, ".ber", 4) || *(ext + 4) != '\0')
		error("Error: the map should have .ber extention\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Error: could open the map\n");
	return (fd);
}

static char	*load_map_from_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*new_line;

	line = NULL;
	new_line = NULL;
	tmp = get_next_line(fd);
	while (tmp && tmp[0] != '\n')
	{
		new_line = ft_strjoin(line, tmp);
		if (!new_line)
			error("Error: something wrong happened\n");
		free(line);
		line = new_line;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp && tmp[0] == '\n')
		free(tmp);
	return (line);
}

static t_map	create_map_from_string(char *line)
{
	t_map	map;

	map.map = ft_split(line, '\n');
	if (!map.map)
		error("Error: something wrong happened\n");
	map.rows = 0;
	while (map.map[map.rows])
		map.rows++;
	map.colums = ft_strlen(map.map[0]);
	return (map);
}

t_map	load_map(char *filename)
{
	t_map	map;
	int		fd;
	char	*line;

	fd = open_file(filename);
	line = load_map_from_file(fd);
	map = create_map_from_string(line);
	free(line);
	return (map);
}

void	free_map(t_map map)
{
	int	y;

	y = 0;
	while (map.map[y])
		free(map.map[y++]);
	free(map.map);
	get_next_line(-2);
}
