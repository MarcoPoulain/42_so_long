/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:56:42 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 13:08:16 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_dispatch(const char *format, va_list args)
{
	int		i;
	int		count;
	char	glyph;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			glyph = extract_glyph(format, &i);
			count += dispatch(glyph, args);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count = parse_dispatch(format, args);
	va_end(args);
	return (count);
}
