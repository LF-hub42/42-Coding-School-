/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:36:45 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/30 00:57:04 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	count_seperator;
	int	index;

	count_seperator = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] && str[index] == sep)
			index++;
		if (str[index])
		{
			count_seperator++;
			while (str[index] && str[index] != sep)
				index++;
		}
	}
	return (count_seperator);
}

static char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	**ft_fill_words(char **split, char const *s, char c)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	end = 0;
	j = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			split[j] = ft_substr(s, start, end - start);
			if (!split[j])
				return (ft_free(split));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char csa)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, csa) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_words(split, s, csa));
}

// ft_split teilt den String s in Teilstrings auf
// getrennt durch das Zeichen c
// Zuerst zählt count, wie viele Wörter (w) es gibt,
// um Speicherplatz für das Ergebnis zu reservieren.
// Dann wird der String mit zwei
// Indizes (start und end) durchlaufen:
// start überspringt Trennzeichen,
// end sucht das Ende eines Wortes,
// Das Wort wird mit ft_substr kopiert.
// Am Ende steht ein NULL-Zeiger, der das Array beendet.

// int main()
// {
// 	const char *str = "Hello";

// 	ft_split(str, 'c');
// 	ft_strtrim()
// }
