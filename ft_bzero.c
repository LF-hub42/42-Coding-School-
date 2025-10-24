/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:21:08 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 15:41:54 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Die Funktion ft_bzero setzt die ersten n Bytes des Speicherbereichs,
** auf den s zeigt, auf den Wert 0/Nullbyte
**
** Sie wird oft benutzt, um Speicher zu "leeren" oder zu initialisieren,
** z. B. bevor man ihn für einen String oder eine Struktur verwendet.
**
** Parameter:
** s : Zeiger auf den Speicherbereich, der auf 0 gesetzt werden soll
** n : Anzahl der Bytes, die auf 0 gesetzt werden sollen
**
** Rückgabewert:
** Keiner daher (void)
*/

void	ft_bzero(void *memory_block, size_t number_of_bytes)
{
	size_t			index;
	unsigned char	*byte_pointer;

	// Casten des void-Zeiger auf unsigned char*, um Byte-für-Byte zu arbeiten.
	// unsigned char ist 1 Byte groß, um byte fuer byte durchzuarbeiten

	byte_pointer = (unsigned char *)memory_block;

	index = 0;

	// Solange index kleiner als die gewünschte Anzahl von Bytes ist

	while (index < number_of_bytes)
	{

		byte_pointer[index] = 0;

		index++;
	}
}

