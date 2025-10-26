/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:24:26 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 00:45:36 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t number_of_bytes)
{
	unsigned char		*destination_bytes;
	const unsigned char	*source_bytes;

	if (!dest && !source)
		return (NULL);
	destination_bytes = (unsigned char *)dest;
	source_bytes = (const unsigned char *)source;
	while (number_of_bytes--)
	{
		*destination_bytes = *source_bytes;
		destination_bytes++;
		source_bytes++;
	}
	return (dest);
}

// #include "libft.h"

// // Die Funktion ft_memcpy kopiert einen
//Speicherbereich von einer Quelle (source)
// // zu einem Zielbereich (destination).
//Es werden genau 'number_of_bytes' Bytes kopiert.
// // Wenn sowohl 'destination' als auch
//'source' NULL sind, wird NULL zurückgegeben.

// // Der Rückgabewert:
// // Ein Zeiger auf den Zielbereich (destination)
