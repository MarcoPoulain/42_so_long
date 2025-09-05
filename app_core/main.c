/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:50:22 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/05 14:20:15 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

int	main(void)
{
	char	**map;
	int		fd;
	int		lines_count;
	int		i;

	fd = check_open_readonly("app_core/maps/test.ber");
	lines_count = count_lines(fd);
	close(fd);
	fd = check_open_readonly("app_core/maps/test.ber");
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
		ft_printf("%s", map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
