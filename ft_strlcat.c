/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:17:46 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 00:48:09 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	nsrc;
	size_t	ndst;
	size_t	cpy;

	nsrc = ft_strlen(src);
	ndst = ft_strlen(dst);
	if (ndst >= size)
		return (nsrc + size);
	if (nsrc + ndst >= size)
		cpy = size - ndst - 1;
	else
		cpy = nsrc;
	if (size > 0)
	{
		ft_memcpy(dst + ndst, src, cpy);
		dst[ndst + cpy] = '\0';
	}
	return (nsrc + ndst);
}
Funktionen: strlcpy() und strlcat()

// Dienen zum Kopieren bzw. Anhängen von Strings.

// Sie sind sicherere Alternativen
// zu strncpy() und strncat().

// Beide Funktionen bekommen die Gesamtgröße des
// Puffers (size) als Parameter, nicht nur die Länge.

// Sie garantieren eine NUL-Terminierung
// ('\0'), solange Platz vorhanden ist.

// size muss den Platz für das
// NUL-Zeichen mit einschließen.

// Arbeiten nur mit gültigen C-Strings
// (also Strings, die bereits NUL-terminiert sind).

// Funktionsweise:

// strlcpy(dst, src, size):
// Kopiert maximal size - 1 Zeichen von src nach
// dst und fügt ein abschließendes NUL-Zeichen hinzu.

// strlcat(dst, src, size):
// Hängt src an dst an, aber nur bis size - strlen(dst)
// - 1 Bytes, und sorgt ebenfalls für NUL-Terminierung.
