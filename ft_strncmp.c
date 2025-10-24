/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:19:23 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 20:01:55 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] == s2[index] && index < n)
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	if (s1[index] == '\0' && index < n)
		return (0 - (unsigned char)s2[index]);
	else if (s2[index] == '\0' && index < n)
		return ((unsigned char)s1[index]);
	else if (index < n)
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	else
		return (0);
}
// Die Funktion strncmp vergleicht zwei Strings (Zeichenketten)
// bis zu einer bestimmten Anzahl von Zeichen (n).
// Sie wird oft benutzt, um zu prüfen, ob zwei Strings gleich
// sind oder in welcher Reihenfolge sie alphabetisch
// stehen — aber nur bis maximal n Zeichen.
