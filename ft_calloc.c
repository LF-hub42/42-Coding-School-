/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:52:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/26 20:27:59 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		count;

	count = nmemb * size;
	if (count > PTRDIFF_MAX)
		return (NULL);
	pointer = malloc(count);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, size);
	return (pointer);
}

// // Ordnet Speicher für ein Array von num-Objekten der Größe zu
// und initialisiert alle Bytes im zugeordneten Speicher auf null.
// // Wenn die Zuordnung erfolgreich ist, wird ein Zeiger auf das niedrigste
// // (erste) Byte im zugeordneten Speicherblock zurückgegeben,
// // das für jeden Objekttyp mit grundlegender Ausrichtung
// entsprechend ausgerichtet ist. Wenn size null ist, ist das
// Verhalten implementierungsdefiniert
// // (es kann ein NULL-Zeiger zurückgegeben werden,
// // 	oder es wird ein Zeiger ungleich NULL zurückgegeben
// der nicht für den Zugriff auf den Speicher verwendet werden darf
