/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:56:57 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 13:25:39 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "printers/printers.h"
# include "libft.h"

int		ft_printf(const char *format, ...);
char	extract_glyph(const char *format, int *i);
int		dispatch(char glyph, va_list args);

#endif
