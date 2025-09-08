/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:59:27 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/06 16:30:47 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**make_map_arr(int fd, int line_count)
{
	int		i;
	char	*line;
	char	**map;
	size_t	len;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_point	find_player(char **map)
{
	int		i;
	int		j;
	t_point	player;

	i = 0;
	player.x = -1;
	player.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	mark_visited(char **map, int x, int y)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (map[height])
		height++;
	while (map[0][width])
		width++;
	if ((x >= 0 && x < width) && (y >= 0 && y < height))
	{
		if (map[y][x] != '1' && map[y][x] != 'P' && map[y][x] != 'V'
			&& map[y][x] != 'c' && map[y][x] != 'e')
		{
			if (map[y][x] == 'C')
				map[y][x] = 'c';
			else if (map[y][x] == 'E')
				map[y][x] = 'e';
			else
				map[y][x] = 'V';
		}
	}
}
