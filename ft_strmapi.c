/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:01:20 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/28 17:32:57 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char *ft_strmapi(char const *s, char (*f)(unsignedint, char));

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
// Erstellt einen neuen String, in dem auf jedes Zeichen des
// Eingabestrings eine Funktion angewendet wird,
// unter Übergabe des Index und des Zeichens.
