/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_glyph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:30:36 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:10:03 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	extract_glyph(const char *format, int *i)
{
	char	c;

	(*i)++;
	c = format[*i];
	if (
		c == 'c' || c == '%' || c == 'd' || c == 'i'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (c);
	return (0);
}
