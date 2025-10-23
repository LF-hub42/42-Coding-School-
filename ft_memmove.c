/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:34:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 13:47:21 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Die Funktion memmove() kopiert n Bytes von Speicherbereich Quelle nach Speicherbereich Ziel.
// Die Speicherbereiche dürfen sich überschneiden...
// Zuerst werden die Bytes von Quelle in einen temporären Bereich kopiert, der nicht mit Quelle oder Ziel überlappt.
// Anschließend wird von dort nach Ziel kopiert.


#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t number_of_bytes)
{
	// Wenn Quelle und Ziel NULL sind, gibt es nichts zu tun
	if (!destination && !source)
		return (NULL);

	// checkt ob sich die Speicherbereiche überlappen
	// Wenn Quelle VOR dem Ziel liegt, kopieren wir rückwärts
	if (source < destination)
	{
		// Rückwärtskopieren: wir beginnen am Ende und gehen nach vorne
		while (number_of_bytes--)
		{
			((unsigned char *)destination)[number_of_bytes]
				= ((const unsigned char *)source)[number_of_bytes];
		}
	}
	else
	{
		// Kein Überlappungsproblem,einfach normales memcpy verwenden.
		ft_memcpy(destination, source, number_of_bytes);
	}

	// Gib den Zeiger auf das Ziel zurück
	return (destination);
}
