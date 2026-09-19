/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:21:08 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 00:42:04 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *memory_block, size_t number_of_bytes)
{
	size_t			index;
	unsigned char	*byte_pointer;

	byte_pointer = (unsigned char *)memory_block;
	index = 0;
	while (index < number_of_bytes)
	{
		byte_pointer[index] = 0;
		index++;
	}
}

// void *memory_block ein Zeiger auf einen beliebigen
// Speicherbereich (untypisiert).
// ft_bzero soll die ersten number_of_bytes Bytes
// dieses Bereichs auf 0 setzen.

// size_t number_of_bytes Anzahl der Bytes, die auf 0 gesetzt
// werden sollen (günstig für Größen/Indizes).
