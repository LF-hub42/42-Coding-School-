/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:52:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 20:17:10 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	pointer = malloc(total);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total);
	return (pointer);
}

// Die Funktion reserviert Speicher für ein Array
// (bestehend aus num Objekten mit jeweils size Bytes)
// und setzt alle Bytes auf 0.
// Wenn die Speicherzuweisung gelingt, gibt sie einen
// Zeiger auf den Anfang des zugewiesenen Speicherblocks zurück.
// Falls size = 0 ist, hängt das Verhalten von der
// Implementierung ab es kann entweder
// NULL zurückgegeben werden oderein gültiger, aber nicht nutzbarer Zeiger.
