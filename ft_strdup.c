/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:15:22 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 01:02:27 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		nmem;
	int		i;

	nmem = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * nmem);
	if (!dup)
		return (NULL);
	while (s[i] && i < nmem - 1)
	{
		dup[i] = s[i];
		i++;
	}
	if (nmem > 0)
		dup[i] = '\0';
	return (dup);
}
// Erstellt eine neue Kopie eines Strings s1 im dynamisch allozierten Speicher.
// Gibt einen Zeiger auf diese Kopie zurück.
// Die ursprüngliche Zeichenkette bleibt unverändert.
