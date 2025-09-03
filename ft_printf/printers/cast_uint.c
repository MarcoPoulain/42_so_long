/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:03:50 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:11:31 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static int	ft_putuint(unsigned int n)
{
	char			buffer[10];
	unsigned int	i;
	unsigned int	count;
	long			nb;

	i = 0;
	nb = n;
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (nb > 0)
	{
		buffer[i++] = nb % 10 + '0';
		nb /= 10;
		count ++;
	}
	while (i--)
		ft_putchar(buffer[i]);
	return (count);
}

int	cast_uint(unsigned int n)
{
	return (ft_putuint(n));
}
