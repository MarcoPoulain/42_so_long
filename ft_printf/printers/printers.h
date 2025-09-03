/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:26:01 by kassassi          #+#    #+#             */
/*   Updated: 2025/08/19 14:14:39 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include "libft.h"

int	cast_char(char c);
int	cast_int(int n);
int	cast_string(char *str);
int	cast_uint(unsigned int n);
int	cast_hex(unsigned int n);
int	cast_uphex(unsigned int n);
int	cast_ptr(void *ptr);

#endif
