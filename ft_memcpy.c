/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:24:26 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 13:40:33 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Die Funktion ft_memcpy kopiert einen Speicherbereich von einer Quelle (source)
// zu einem Zielbereich (destination). Es werden genau 'number_of_bytes' Bytes kopiert.
// Wenn sowohl 'destination' als auch 'source' NULL sind, wird NULL zurückgegeben.

// Der Rückgabewert:
// Ein Zeiger auf den Zielbereich (destination)

void	*ft_memcpy(void *destination, const void *source, size_t number_of_bytes)
{
	unsigned char		*destination_bytes;
	const unsigned char	*source_bytes;

	// Wenn weder Quelle noch Ziel existieren, kann nichts kopiert werden
	if (!destination && !source)
		return (NULL);

	// Wir casten die Zeiger auf unsigned char, damit wir Byte für Byte kopieren können
	destination_bytes = (unsigned char *)destination;
	source_bytes = (const unsigned char *)source;

	// Kopiere jedes Byte einzeln von der Quelle zum Ziel
	while (number_of_bytes--)
		*destination_bytes++ = *source_bytes++;

	// Gib den Zeiger auf das Ziel zurück
	return (destination);
}
