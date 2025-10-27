/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:20:17 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 01:02:42 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	if (!n || big == little)
		return ((char *)(big));
	big--;
	while (len-- >= n && *++big)
		if (!ft_strncmp(big, little, n))
			return ((char *)big);
	return (NULL);
}
// Die Funktion strstr() sucht das erste Vorkommen
//der nullterminierten Zeichenkette
// little in der Zeichenkette big.
// Die Funktion strcasestr() macht dasselbe
// ignoriert dabei jedoch die Groß- und Kleinschreibung.
