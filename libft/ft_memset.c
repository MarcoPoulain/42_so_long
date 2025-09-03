/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:58:38 by kassassi          #+#    #+#             */
/*   Updated: 2025/05/07 09:58:04 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memset() function fills the first count bytes of the memory area
// pointed to by dest with the constant byte ch

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)dest;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*ptr = ch;
		i++;
		ptr++;
	}
	return (dest);
}
