/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:22:50 by kassassi          #+#    #+#             */
/*   Updated: 2025/09/05 17:02:54 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_rectangle(int width, int height, char **map)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) != (size_t)width)
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_glyphset(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

static void	count_glyphs(t_glyph *glyph, char c)
{
	if (c == 'P')
		glyph->p++;
	else if (c == 'E')
		glyph->e++;
	else if (c == 'C')
		glyph->c++;
}

static int	only_essentials_glyph(char **map)
{
	int		i;
	int		j;
	t_glyph	glyph;

	i = 0;
	glyph.p = 0;
	glyph.e = 0;
	glyph.c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			count_glyphs(&glyph, map[i][j]);
			j++;
		}
		i++;
	}
	if (glyph.p != 1 || glyph.e != 1 || glyph.c == 0)
		return (0);
	return (1);
}

int	check_map(int width, int height, char **map)
{
	if (!is_valid_rectangle(width, height, map))
	{
		write(2, "Error\nThe map is not a rectangle\n", 34);
		return (0);
	}
	if (!is_valid_glyphset(map))
	{
		write(2, "Error\nMap has unauthorized glyph\n", 33);
		return (0);
	}
	if (!only_essentials_glyph(map))
	{
		write(2, "Error\nInvalid numner of P, E, or C in map\n", 41);
		return (0);
	}
	if (!check_walls(width, height, map))
	{
		write(2, "Error\nMap is not surrounded by walls\n", 37);
		return (0);
	}
	return (1);
}
