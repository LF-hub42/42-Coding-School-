/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:52:38 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 01:11:32 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		count;

	count = nmemb * size;
	if (count > (PTRDIFF_MAX))
		return (NULL);
	pointer = malloc(count);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, size);
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
