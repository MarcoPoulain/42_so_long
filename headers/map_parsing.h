/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:54:47 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/06 15:42:26 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

typedef struct s_glyph
{
	int	p;
	int	e;
	int	c;
}	t_glyph;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		check_open_readonly(char *file);
void	free_map(char **map);
int		count_lines(int fd);
char	**make_map_arr(int fd, int line_count);
int		check_map(int width, int height, char **map);
int		check_walls(int width, int height, char **map);
t_point	find_player(char **map);

#endif
