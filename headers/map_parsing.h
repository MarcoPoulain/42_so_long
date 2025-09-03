/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:54:47 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/03 15:49:02 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

int		check_open_readonly(char *file);
void	free_map(char **map);
int		count_lines(int fd);
char	**make_map_arr(int fd, int line_count);
int		is_valid_rectangle(int width, int height, char **map);
int		is_valid_glyphset(char **map);
int		check_map(int width, int height, char **map);

#endif
