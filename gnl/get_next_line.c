/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:22:49 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/15 11:50:47 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*find_next_leftovers(char *leftovers)
{
	int		i;
	char	*str;

	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	if (!leftovers[i])
	{
		free(leftovers);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftovers) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	ft_strcpy(str, leftovers + i);
	free(leftovers);
	return (str);
}

char	*find_line(char *leftovers)
{
	int		i;
	char	*line;

	if (!leftovers[0])
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char)
			* (i + 2 * (leftovers[i] == '\n') + 1 * (leftovers[i] != '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*find_leftovers(int fd, char *leftovers)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && (!leftovers || !ft_strchr(leftovers, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftovers);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftovers = strjoin(leftovers, buffer);
	}
	free(buffer);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(leftovers), NULL);
	leftovers = find_leftovers(fd, leftovers);
	if (leftovers == NULL)
		return (NULL);
	line = find_line(leftovers);
	leftovers = find_next_leftovers(leftovers);
	return (line);
}
