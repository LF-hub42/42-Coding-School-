/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:20:17 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 20:22:28 by ekypraio         ###   ########.fr       */
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
// The  strstr()  function locates the first occurrence of the null-termi-
// ated string little in the null-terminated string big.
// The strcasestr()	function is similar to strstr(), but ignores the  case
// of both strings.
