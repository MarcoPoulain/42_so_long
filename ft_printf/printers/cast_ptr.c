/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:56:50 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:11:13 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include <unistd.h>

static int	cast_hex_long(unsigned long n)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		count;

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
		n /= 16;
		count++;
	}
	while (i--)
		ft_putchar(buffer[i]);
	return (count);
}

int	cast_ptr(void *ptr)
{
	unsigned long	hexptr;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	hexptr = (unsigned long)ptr;
	ft_putstr("0x");
	if (hexptr == 0)
	{
		ft_putchar('0');
		return (1 + 2);
	}
	count = cast_hex_long(hexptr);
	return (count + 2);
}
