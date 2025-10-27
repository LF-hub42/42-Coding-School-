/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:18:33 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 13:00:18 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

// Parameter
// s1: Die Präfixzeichenfolge.
// s2: Die Suffixzeichenfolge.

// Rückgabewert:
// Die neue Zeichenfolge.
// NULL, wenn die Zuordnung fehlschlägt.
// Beschreibung Ordnet mit malloc
// zu und gibt eine neue Zeichenfolge,
// die das Ergebnis der Verkettung ist von 's1' und 's2'.
