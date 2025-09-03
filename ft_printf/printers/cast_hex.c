/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:27:16 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:10:52 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

int	cast_hex(unsigned int n)
{
	char			*base;
	char			buffer[8];
	unsigned int	i;
	unsigned int	count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n = n / 16;
		count++;
	}
	while (i > 0)
	{
		ft_putchar(buffer[--i]);
	}
	return (count);
}
