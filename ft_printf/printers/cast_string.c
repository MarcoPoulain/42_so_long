/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:15:09 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:11:21 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include <unistd.h>

int	cast_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr(str);
	return (ft_strlen(str));
}
