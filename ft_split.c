/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:36:45 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/29 19:01:14 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

// Parameter:
// s: Die zu trennende Zeichenkette.
// c: Das Trennzeichen (Delimiter).

// Rückgabewert:
// Ein Array neuer Zeichenketten, die durch das
//Aufteilen von s mithilfe des Trennzeichens c entstehen.
// NULL, wenn die Speicherallokation fehlschlägt.

// Externe Funktionen:
// malloc, free

// Beschreibung:
// Reserviert Speicher (mit malloc(3))
//und gibt ein Array von Zeichenketten zurück,
// das durch das Aufteilen von s anhand
//des Zeichens c erzeugt wurde.
// Das Array muss mit einem NULL Zeiger enden.
