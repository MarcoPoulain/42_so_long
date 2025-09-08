/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:50:22 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/06 15:37:38 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		fd;
	int		lines_count;
	int		i;
	t_point	player;

	if (argc != 2)
		return (1);
	fd = check_open_readonly(argv[1]);
	lines_count = count_lines(fd);
	close(fd);
	fd = check_open_readonly(argv[1]);
	map = make_map_arr(fd, lines_count);
	close(fd);
	if (!check_map(ft_strlen(map[0]), lines_count, map))
	{
		free_map(map);
		return (1);
	}
	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("ligne %d: %s\n", i, map[i]);
		i++;
	}
	player = find_player(map);
	if (player.x > 0 && player.y > 0)
		ft_printf("P se trouve en %d, %d\n", player.x, player.y);
	free_map(map);
	return (0);
}
