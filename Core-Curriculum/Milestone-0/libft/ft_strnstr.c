/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:20:17 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/29 13:54:41 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && (i
				+ j) < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// Die Funktion strstr() sucht das erste Vorkommen
// der nullterminierten Zeichenkette
// little in der Zeichenkette big.
// Die Funktion strcasestr() macht dasselbe
// ignoriert dabei jedoch die Groß- und Kleinschreibung.
// int	main(void)
// {
// 	const char *big = "helloIamstring";
// 	const char *little = "Iam";
// 	printf("%s\n", ft_strnstr(big, little, 8));
// 	return (0);
// }
