/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:11:30 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 13:37:56 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch(char glyph, va_list args)
{
	if (glyph == 'c')
		return (cast_char(va_arg(args, int)));
	if (glyph == 'd' || glyph == 'i')
		return (cast_int(va_arg(args, int)));
	if (glyph == 's')
		return (cast_string(va_arg(args, char *)));
	if (glyph == 'u')
		return (cast_uint(va_arg(args, unsigned int)));
	if (glyph == 'x')
		return (cast_hex(va_arg(args, unsigned int)));
	if (glyph == 'X')
		return (cast_uphex(va_arg(args, unsigned int)));
	if (glyph == 'p')
		return (cast_ptr(va_arg(args, void *)));
	if (glyph == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}
